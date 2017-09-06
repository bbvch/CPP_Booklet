/**
* Example for section 2.18
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the usage of return type deduction
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <utility>
#include <vector>
//@37
template <typename T, typename U> auto add(T t, U u) {
  // return type deducted from operator+(T, U)
  return t + u;
}
//@37

//@38
// C++11 Version
template <typename Container, typename Index>
auto assignValue11(Container &&cont, Index idx)
    -> decltype(std::forward<Container>(cont)[idx]) {

  return std::forward<Container>(cont)[idx];
}

// C++14 Version
template <typename Container, typename Index>
decltype(auto) assignValue14(Container &&cont, Index idx) {

  return std::forward<Container>(cont)[idx];
}
//@38

decltype(auto) func1() {
  int x = 777;
  return x; // decltype(x) is int
  // func1 returns 'int'
}
decltype(auto) func2() {
  int x = 777;
  return (x); // decltype( (x) ) is int&
  // func2 returns now "int&”
}

int main(int, char **) {
//@38
  // this allowes the following initialisation,
  // note the missing template arguments
  std::vector<int> vec;
  assignValue14(std::vector<int>(), 1) = 10;
//@38
}
