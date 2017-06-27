#include <exception>

namespace {
class myException : std::exception {
  virtual const char *what() const noexcept { return "myException happened"; }
};
}

class A {
public:
  void throwing_function() noexcept(false) { // marked as possibly throwing
    if (_a < 500) {
      throw myException();
    }
  }
  void exceptionless_func() noexcept { }
  void bad_func() noexcept {
    // putting a throw-statement here will NOT break compilation
    // even if it violates the noexcept specifier
    throw myException();
  }

  // the same as noexcept(false)
  void unspecified_func() {  }

  // deprecated since C++11 but the same as noexcept
  void old_syntax_func() throw() { }

  // deprecated since C++11 but the same as noexcept(false) 
  // dynamic exception specifications are no longer allowe in C++17
  // void old_syntax_throwing_func() throw(myException) { throw myException(); }

private:
  int _a{1000};
};

int main(int argc, char **argv) {
  A a;

  static_assert(noexcept(a.exceptionless_func()), "not throwing");
  static_assert(!noexcept(a.throwing_function()), "not throwing");
  static_assert(!noexcept(a.unspecified_func()), "possibly throwing");
  static_assert(noexcept(a.bad_func()),
                "bad func pretends to be not throwing");
  static_assert(noexcept(a.old_syntax_func()), "not throwing");
  //static_assert(!noexcept(a.old_syntax_throwing_func()), "possibly throwing");
}
