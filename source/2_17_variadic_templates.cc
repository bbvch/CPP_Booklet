/**
* Example for section 2.17
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the usage of variadic templates
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <algorithm>
#include <iostream>
#include <memory>

struct Dummy {
  int x;
  char c;
};
//@33
// variadic template function definition
template <typename... Args> void aFunction(Args... args) {}
//@33

//@34
// variadic template class definition
template <typename... Args> class aClass {};
//@34

//@35
std::string reorder_and_concat() { return std::string(); } // End of recursion

// recursion popping the first template argument and concatenating
template <typename T, typename... Args>
std::string reorder_and_concat(T t, Args... args) {
  std::string to_be_sorted(t);
  std::sort(to_be_sorted.begin(), to_be_sorted.end());
  return to_be_sorted + reorder_and_concat(args...);
}
//@35

// using fold expression for simple operator +
/*
 * Supported operators are
 * - boolean (&&, ||, <, >, ==, !=)
 * - mathematical (+, -, *, /, %)
 * - bitwise (&, |, ^, >>, <<)
 * - memory (de-)referencing and obiect concatenation (.*, ->*)
 * - assignement = and combinations such as /=, &=...
 * - unpacking (,) [can be used to forward to normals functions]
 *
 * folds can be written left or right associative as well as as
 * unary or as binary operators. Note that in a binary fold the operators cannot
 * be mixed
 */

//@36
template <typename... Args> auto binary_left_fold(Args &&... args) {
  return (10 + ... + args);
}

template <typename... Args> auto unary_left_fold(Args &&... args) {
  return (... - args);
}

template <typename... Args> auto unary_right_fold(Args &&... args) {
  return (args - ...);
}
//@36
// helper function
const auto print = [](const auto &obj) {
  std::cout << "Unpacked: " << obj << "\n";
};

template <typename... Args> void unpack(Args... args) {
  (print(std::forward<Args>(args)), ...);
}

int main(int, char **) {
//@33
  aFunction(42, 1.14159, "Hello", Dummy());
  aFunction(1, 2, 3, 4, 5);
//@33

//@34
  aClass<std::string, int> ac1;
  aClass<char, char, double, std::string> ac2;
  aClass<> ac3;
//@34

//@35
  // returns "ABC"
  std::cout << reorder_and_concat("CBA") << "\n";

  // returns ABCJKL
  std::cout << reorder_and_concat("CBA", "KLJ") << "\n";

  // returns ABCJKLXYZ
  std::cout << reorder_and_concat("CBA", std::string("KLJ"), "ZYX") << "\n";
//@35

//@36
  std::cout << binary_left_fold(1) << "\n";       // 11 (10 + 1)
  std::cout << binary_left_fold(1, 2, 3) << "\n"; // 16 (10 + 1 + 2 +3)

  // 115.499L (internal cast to double) (10 + 1+ 4.5f + 99.9999L)
  std::cout << binary_left_fold(1, 4.5f, 99.999L) << "\n";

  std::cout << unary_left_fold(10, 3, 2) << "\n";  // (10 - 3) -2 = 5
  std::cout << unary_right_fold(10, 3, 2) << "\n"; // 10 - (3 -2) = 9
 
//@36
 unpack("ABC", 55, 1.345f);
}
