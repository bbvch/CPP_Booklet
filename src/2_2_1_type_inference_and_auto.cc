/**
* Example for section 2.3
* of the C++ Booklet
* published by bbv software services AG (c) 2020
*
* This example illustrates the use of the 'auto' keyword and type inference
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <vector>

int main(int, char **) {
//@6
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
//@6
}
