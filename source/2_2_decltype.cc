/**
* Example for section 2.18
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
*  This example illustrates the use of decltype
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <string>

int main(int, char **) {
  const std::string &other{"Abracadabra"};
  const std::string &name();

  // using decltype to "copy" the type from an existing object
  decltype(name()) n1(other); // n1 containts the type 'const std::string&'

  std::string s1;
  decltype(s1) s2; // s2 contains the type std::string
  struct Foo {
    int i;
  };
  Foo foo;
  decltype(foo.i) j;      // j contains type int
  decltype((foo.i)) k(j); // k contains type int&, because
                          // (foo.i) is an expression which has an adress
}
