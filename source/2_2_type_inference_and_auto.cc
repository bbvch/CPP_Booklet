/**
* Example for section 2.2
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the use of the 'auto' keyword and type infrence
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <vector>

//@6
// syntax for trailing return type
auto fac(int n) -> int { return n <= 1 ? 1 : n * fac(n - 1); }
//@6

int main(int, char **) {
//@7
  auto x = 42; // x is an int
#ifdef EXPECT_FAILED_COMPILATION
  x = "fortytwo"; // Error, because x is already an int
#endif
  std::vector<int> vec{1000, 1001, 1002, 1003};
  auto it0 = vec.begin();  // it0 is a vector<T>::iterator
  auto st0(vec[4]);        // st0 is an int
  auto &st1 = vec[4];      // st1 is an int&
  const auto &s1 = vec[4]; // s1 const int&
  auto it1 = vec.cbegin(); // it1 is a vector<int>::const_iterator
  auto sil{vec[4]};        // sil is a std:initializer_list<int>
//@7
}
