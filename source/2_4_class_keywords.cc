/**
* Example for section 2.4
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
*  This example illustrates the
*
* SPDX-License-Identifier: GPL-3.0
*
**/

//@10
struct Dummy {
  Dummy() = default;
  // specify destructor as virtual but use default implementation
  virtual ~Dummy() = default;

#ifdef EXPECT_FAILED_COMPILATION
  Dummy(int x) = default; // error this is not a default constructur
#endif

protected:
  // protect move, but use default implementation
  Dummy(Dummy &&other) = default;
  Dummy &operator=(Dummy &&other) = default;

  // protect copy, but use default implementation
  Dummy(const Dummy &other) = default;
  // also protect assignemt operator
  Dummy &operator=(const Dummy &rhs) = default;
};
//@10

//@11
struct DummyNonCopyable {
  DummyNonCopyable() = default;

  // disables copying the object through construction
  DummyNonCopyable(const Dummy &) = delete;
  // disables copying the object through assignement
  DummyNonCopyable &operator=(const Dummy &rhs) = delete;
};

struct NonDefaultConstructible {
  // this struct can only be constructed through a move or copy
  NonDefaultConstructible() = delete;
};

struct NonContstructableByValue {
  void f(int){};
  void f(double) = delete; // prevents f.foo(3.14)
};
//@11

//@16
struct ExplicitConversion {
  // Conversion to bool overwritten
  explicit operator bool() { return true; }
};
//@16

int main(int, char **) {
//@16

  ExplicitConversion myBool;
  if (myBool) {
  }                         // OK
  int a = (myBool) ? 3 : 4; // OK
#ifdef EXPECT_FAILED_COMPILATION
  int b = myBool + a; // Error, only conversion allowed
#endif
//@16
}
