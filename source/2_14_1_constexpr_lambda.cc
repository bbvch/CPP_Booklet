/**
* Example for section 2.14.1
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
*  This example illustrates the use of constant expression lambdas an the use of
*the mutable keyword
* in that context
*
* SPDX-License-Identifier: GPL-3.0
*
**/

//@29
class MutableClass {
public:
  int &non_const_a() { return _a; }
  const int &const_a() const { return _a; }

private:
  int _a{1000};
};
//@29
int main(int argc, char **argv) {
//@29
  constexpr int c{1000};

  // explicitely constexpr lambda
  const auto constexpr_func = [&c](int v) constexpr { return c + v; };

  // implicitely constexpr, no warning if no longer constexpr
  const auto const_func = [&c](int v) { return c + v; };

  MutableClass obj;
  // an explicitely non-constexpr labmda that takes obj by value and modifies it
  // Needs mutable keyword to access non_const_a()
  auto non_const_func = [obj](int v) mutable { obj.non_const_a() += v; };

  // if obj is passed by reference the mutable keyword is no longer needed
  auto non_const_func_with_ref = [&obj](int v) { obj.non_const_a() += v; };
//@29
  return 0;
}
