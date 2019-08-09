#ifdef __cpp_coroutines

#include <iostream>
#include <vector>
#include <type_traits>

#define Example 3

// experimental ..?
// #include <coroutine>
#include <experimental/coroutine>

    class resumable {
    public:
      struct promise_type;
      using coro_handle = std::experimental::coroutine_handle<promise_type>;
      resumable(coro_handle handle) : handle_(handle) { assert(handle); }

      // don't want to copy, don't want to move
      resumable(resumable&) = delete;
      resumable(resumable&&) = delete;

#if Example != 3
      const char* return_val();
#elif Example == 3
      const char* recent_val();
#endif
      // returns true if coroutine can be resumed
      bool resume() {
        if (not handle_.done())
          handle_.resume();
          // if and only if the coroutine has reached the final suspend:
          // done returns true
        return not handle_.done();
      }
      // coroutine destruction => destroy handle
      ~resumable() { handle_.destroy(); }
    private:
      // the coroutine_handle will be created by compiler
      // side note: it's NOT threadsafe!!
      coro_handle handle_;
    };

    struct resumable::promise_type {
      using coro_handle = std::experimental::coroutine_handle<promise_type>;

      // called to create the resumable object
      // needs the handle which can be created from *this promise
      auto get_return_object() {
        return coro_handle::from_promise(*this);
      }
      // after each suspend resume has to be called
      auto initial_suspend() { return std::experimental::suspend_always(); }
      auto final_suspend() { return std::experimental::suspend_always(); }

      const char * string_;
#if Example == 1
      // needed for co_await (otherwise undefined behaviour)
      // in case of co_return: define return_value
      void return_void() {}
#elif Example == 2
    //void return_void() {}
      void return_value(const char * string) { string_ = string; }
#elif  Example == 3
       void return_void() {};
      auto yield_value(const char* string){
        string_=string;
        return std::experimental::suspend_always();
      }
#endif
      void unhandled_exception() {
        // must be defined how an exception is handled
        std::terminate();
      }
    };

#if Example ==2
// promise returns a reference to the promise object
    const char* resumable::return_val(){
      return handle_.promise().string_;
    }
#elif Example == 3
    const char* resumable::recent_val(){
        return handle_.promise().string_;
    }
#endif

resumable foo(){
#if Example == 1
  std::cout << "Hello" << std::endl;
  co_await std::experimental::suspend_always();
  std::cout << "World" << std::endl;
#endif
#if Example == 2
  std::cout << "Hello" << std::endl;
  co_await std::experimental::suspend_always();
    co_return "Coroutine";
#elif Example == 3
  while(true){
    co_yield "Hello";
    co_yield "Coroutine";
  }
#endif
}

int main(){
  resumable res = foo();
#if Example <3
  while (res.resume()){};
#endif
#if Example == 2
  std::cout << res.return_val() << std::endl;
#elif Example == 3
    int i=10;
    while (i--){
        res.resume();
        std::cout << res.recent_val() << std::endl;
  }
#endif
    return 0;
}

#endif // __cpp_coroutines
