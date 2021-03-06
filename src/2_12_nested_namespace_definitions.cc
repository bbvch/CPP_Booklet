/**
 * Example for section 2.15
 * of the C++ Booklet
 * published by bbv software services AG (c) 2020
 *
 * This example illustrates the syntax for nested namespaces introduced in C++17
 *
 * SPDX-License-Identifier: GPL-3.0
 *
 **/
//@21
namespace A::B::C {
void doMagic() {}
} // namespace A::B::C

int main(int argc, char **argv) {
  A::B::C::doMagic();

  return 0;
}
//@21
