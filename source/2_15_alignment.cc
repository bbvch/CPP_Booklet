/**
* Example for section 2.15
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* this example illustrates the usage of alignof, alignas and offsetof operators
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <cstddef>
#include <iostream>

//@29
struct C {
  char a; // size: 1, alignment: 1, offest 0
  char b; // size: 1, alignment: 1, offset 1
};        // sizeof(C): 2, alignof(C): 1

struct I {
  int n;  // size: 4, alignment: 4, offset 0
  char c; // size: 1, alignment: 1, offset 4
  // + three bytes padding because of alignment 4 of in n
}; // sizeof(I): 8, alignof(I): 4

struct S {
  int a; // size: 4, alignment: 4, offset 0
  int b; // size: 4, alignment: 4, offset 4
  int c; // size: 4, alignment: 4, offset 8
};       // sizeof(S): 12, alignof(S): 4
//@29

//@30
struct X {
  int a;             // size: 4, alignment: 4, offset 0
  alignas(16) int b; // size: 4, alignment: 16, offset 4
  int c;             // size: 4, alignment: 4, offset 20
  // + 8 bytes padding because the forced alignment of b
}; // sizeof(X): 32, alignof(X): 16 (forced by alignas of b)
//@30

int main(int, char **) {
//@29
  std::cout << "sizeof(C) = " << sizeof(C) << " alignof(C) = " << alignof(C)
            << std::endl;
  std::cout << "sizeof(I) = " << sizeof(I) << " alignof(I) = " << alignof(I)
            << std::endl;
  // > sizeof(C) = 2 alignof(C) = 1
  // > sizeof(I) = 8 alignof(I) = 4

  std::cout << "sizeof(S) = " << sizeof(S) << " alignof(S) = " << alignof(S)
            << std::endl;
  std::cout << "offsetof(S,b) = " << offsetof(S, b)
            << " offsetof(S,c) = " << offsetof(S, c) << std::endl;
//@29
//@30
  std::cout << "sizeof(X) = " << sizeof(X) << " alignof(X) = " << alignof(X)
            << std::endl;
  std::cout << "offsetof(X,b) = " << offsetof(X, b)
            << " offsetof(X,c) = " << offsetof(X, c) << std::endl;
//@30
}
