/**
* Example for section 2.11s
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the syntax for nested namespaces introduced in C++17
*
* SPDX-License-Identifier: GPL-3.0
*
**/
//@21
namespace A::B::C {
void doMagic() { 
}
}

int main(int argc, char **argv) {
  A::B::C::doMagic();

  return 0;
}
//@21
