/**
* Example for section 2.22
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of a coroutine using co_await
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
      // forward declare promise_type
      struct promise_type;
      using coroutine_handle = std::experimental::coroutine_handle<promise_type>;
      resumable(coroutine_handle handle) : mhandle(handle) { assert(handle); }

      // don't want to copy, don't want to move
      resumable(resumable&) = delete;
      resumable(resumable&&) = delete;

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
      // suspend_always was chosen arbitrarily
      auto initial_suspend() { return std::experimental::suspend_always(); }
      auto final_suspend() { return std::experimental::suspend_always(); }

      // needed for co_await (otherwise undefined behaviour)
      void return_void() {}

      void unhandled_exception() {
        // must be defined how an exception is handled
        std::terminate();
      }
    };

resumable foo_await()
{
  std::cout << "Hello" << std::endl;
  co_await std::experimental::suspend_always();
  std::cout << "Coroutine co_await" << std::endl;
}
void example_co_await()
{
  resumable res = foo_await();
  while (res.resume()){};
}


int main(){
    example_co_await();
    return 0;
}

#endif // __cpp_coroutines
