/**
* Example for section 2.22
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of a coroutine using co_return
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#ifdef __cpp_coroutines

#include <iostream>
#include <type_traits>

// experimental ..?
#include <experimental/coroutine>

    class resumable {
    public:
      struct promise_type;
      using coroutine_handle = std::experimental::coroutine_handle<promise_type>;
      resumable(coroutine_handle handle) : mhandle(handle) { assert(handle); }

      // don't want to copy, don't want to move
      resumable(resumable&) = delete;
      resumable(resumable&&) = delete;

      const char* return_val();

      // returns true if coroutine can be resumed
      bool resume() {
        if (not mhandle.done())
          mhandle.resume();
          // if and only if the coroutine has reached the final suspend:
          // done returns true
        return not mhandle.done();
      }
      // coroutine destruction => destroy handle
      ~resumable() { mhandle.destroy(); }

    private:
      // the coroutine_handle will be created by compiler
      // side note: it's NOT threadsafe!!
      coroutine_handle mhandle;
    };

    struct resumable::promise_type {
      using coroutine_handle = std::experimental::coroutine_handle<promise_type>;

      // called to create the resumable object
      // needs the handle which can be created from *this promise
      auto get_return_object() {
        return coroutine_handle::from_promise(*this);
      }
      // after each suspend resume has to be called
      auto initial_suspend() { return std::experimental::suspend_always(); }
      auto final_suspend() { return std::experimental::suspend_always(); }

      const char * mstring;

      // in case of co_return it's necessary to implement return_value
      void return_value(const char * string) { mstring = string; }

      void unhandled_exception() {
        // must be defined how an exception is handled
        std::terminate();
      }
    };

    // promise returns a reference to the promise object
    const char* resumable::return_val(){
      return mhandle.promise().mstring;
    }


resumable foo_return()
{
  std::cout << "Hello" << std::endl;
  co_await std::experimental::suspend_always();
  co_return "Coroutine co_return";
}

void example_co_return()
{
  resumable res = foo_return();
  while (res.resume()){};
  std::cout << res.return_val() << std::endl;
}


int main(){
    example_co_return();
    return 0;
}

#else

  #include <iostream>

  int main() {
    std::cout << "coroutines not implemented yet!" << std::endl;
    return 1;
  }

#endif // __cpp_coroutines
