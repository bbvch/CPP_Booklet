/**
 * Example for section @section @title
 * of the C++ Booklet (https://goo.gl/VJ4T3A)
 * published by bvv software services AG (c) 2017
 *
 * This example illustrates the usage of variadic templates
 **/

#include <algorithm>
#include <iostream>
#include <memory>

struct Dummy {
  int x;
  char c;
};

// variadic template function definition
template <typename... Args> void aFunction(Args... args) {}

// variadic template class definition
template <typename... Args> class aClass {};

std::string reorder_and_concat() { return std::string(); } // End of recursion

// recursion popping the first template argument and concatenating
template <typename T, typename... Args>
std::string reorder_and_concat(T t, Args... args) {
  std::string to_be_sorted(t);
  std::sort(to_be_sorted.begin(), to_be_sorted.end());
  return to_be_sorted + reorder_and_concat(args...);
}

// using fold expression for simple operator +
/*
 * Supported operators are
 * - boolean (&&, ||, <, >, ==, !=)
 * - mathematical (+, -, *, /, %)
 * - bitwise (&, |, ^, >>, <<)
 * - memory (de-)referencing and obiect concatenation (.*, ->*)
 * - assignement = and combinations such as /=, &=...
 * - unpacking (,) [can be used to forward to normals functions]
 */
template <typename... Args> auto fold_using_add(Args &&... args) {
  return (... + args);
}

// helper function
const auto print = [](const auto &obj) {
  std::cout << "Unpacked: " << obj << "\n";
};

template <typename... Args> void unpack(Args... args) {
  (print(std::forward<Args>(args)), ...);
}

int main(int, char **) {
  aFunction(42, 1.14159, "Hello", Dummy());
  aFunction(1, 2, 3, 4, 5);

  aClass<std::string, int> ac1;
  aClass<char, char, double, std::string> ac2;
  aClass<> ac3;

  // returns "ABC"
  std::cout << reorder_and_concat("CBA") << "\n";

  // returns ABCJKL
  std::cout << reorder_and_concat("CBA", "KLJ") << "\n";

  // returns ABCJKLXYZ
  std::cout << reorder_and_concat("CBA", std::string("KLJ"), "ZYX") << "\n"
            << std::endl;

  std::cout << fold_using_add(1) << "\n";       // 1
  std::cout << fold_using_add(1, 2, 3) << "\n"; // 6
  std::cout << fold_using_add(1, 4.5f, 99.999L)
            << "\n"; // 105.499L (internal cast to double)

  unpack("ABC", 55, 1.345f);
}
