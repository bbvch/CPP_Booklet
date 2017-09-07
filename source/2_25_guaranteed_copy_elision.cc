/**
* Example for section 2.25
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
*  This example illustrates the copy elision which became mandatory in c++17
*
* SPDX-License-Identifier: GPL-3.0
*
**/

//@52
class A {
public:
  A() = default;
  A(const A &rhs) = delete;
  A(const A &&rhs) = delete;
  ~A() = default;

};

// Without elision this is illegal, as it performs a copy/move of A which has
// deleted copy/move ctors
A f() { return A{}; }
//@52
int main() {

//@52
  // OK, because of copy elision. Copy/Move constructing an anonymous A is not
  // neccessary
  A a = f();
//@52
}
