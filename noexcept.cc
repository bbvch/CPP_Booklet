#include <exception>

namespace {
class myException : std::exception {
  virtual const char *what() const noexcept { return "myException happened"; }
};
}

class Magician {
public:
  void riskyMagic() noexcept(false) { // marked as possibly throwing
    if (_magic < 500) {
      throw myException();
    }
  }
  void magic() noexcept { /** do magic */ }
  void badMagic() noexcept {
    // putting a throw-statement here will NOT break compilation
    // even if it violates the noexcept specifier
    throw myException();
  }

  // the same as noexcept(false)
  void unspecifiedMagic() { /** do magic **/  }

  // deprecated since C++11 but the same as noexcept
  void oldMagic() throw() { /** do magic **/  }

  // deprecated since C++11 but the same as noexcept(false)
  void oldriskyMagic() throw(myException) { throw myException(); }

private:
  int _magic{1000};
};

int main(int argc, char **argv) {
  Magician m;

  static_assert(noexcept(m.magic()), "not throwing");
  static_assert(!noexcept(m.riskyMagic()), "not throwing");
  static_assert(!noexcept(m.unspecifiedMagic()), "possibly throwing");
  static_assert(noexcept(m.badMagic()),
                "bad magic pretends to be not throwing");
  static_assert(noexcept(m.oldMagic()), "not throwing");
  static_assert(!noexcept(m.oldriskyMagic()), "possibly throwing");
}
