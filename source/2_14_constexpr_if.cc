/**
* Example for section 2.14
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the use of constexpr if
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
//@28
// Here Constexpr is used to facilitate template specialisation 'in-place'
template <typename T> class NameByType {
public:
  std::string to_string() {
    if
      constexpr(std::is_pointer<T>::value) { return "Pointer"; }
    else if
      constexpr(std::is_integral<T>::value) { return "Integral"; }
    else if
      constexpr(std::is_same<T, float>::value) { return "Float"; }
    else {
      return "Unknown";
    }
  }
};

// A fixed size storage class that can return differnt types by using auto and
// constexpr if
class MixedStorage {
public:
  template <std::size_t N> auto access() {
    if
      constexpr(N == 0) { return a; } // int
    if
      constexpr(N == 1) { return b; } // char
    if
      constexpr(N == 2) { return c; } // string
    if
      constexpr(N == 3) { return d; } // vector
    else if                           // return a fixed size array of size N
      constexpr(N > 3) { // Condition needs explicit specification or else
                         // return type cannot be deducted correctly
        std::array<int, N> r;
        return std::move(r);
      }

#ifdef EXPECT_FAILED_COMPILATION
    else {
      return 123;
    }
#endif
  }

private:
  int a = 1000;
  char b = 64;
  std::string c{"Hello world"};
  std::vector<char> d{'a', 'b', 'c', 'd'};
};
//@28
int main(int argc, char **argv) {

  std::cout << NameByType<int>().to_string() << std::endl;         // Integral
  std::cout << NameByType<char *>().to_string() << std::endl;      // Pointer
  std::cout << NameByType<float>().to_string() << std::endl;       // Float
  std::cout << NameByType<std::string>().to_string() << std::endl; // Unknown

  std::cout << std::endl;
  MixedStorage store;
  std::cout << store.access<0>() << std::endl; // 1000
  std::cout << store.access<1>() << std::endl; // 64
  std::cout << store.access<2>() << std::endl; // "Hello World"
  for (const auto &v : store.access<3>()) {    // vector returned
    std::cout << v << ", ";
  }
  std::cout << std::endl;

  for (const auto &v : store.access<16>()) { // fixed size array returned
    std::cout << v << ", ";
  }
  std::cout << std::endl;

  return 0;
}
