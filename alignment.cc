/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

#include <cstddef>
#include <iostream>

struct C {
  char a;
  char b;
};
struct I {
  int n;
  char c;
};

struct S {
  int a;
  int b;
  int c;
};
struct X {
  int a;
  alignas(16) int b;
  int c;
};

int main(int, char **) {

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
  std::cout << "sizeof(X) = " << sizeof(X) << " alignof(X) = " << alignof(X)
            << std::endl;
  std::cout << "offsetof(X,b) = " << offsetof(X, b)
            << " offsetof(X,c) = " << offsetof(X, c) << std::endl;
}
