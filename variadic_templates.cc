/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
* This example illustrates the usage of variadic templates
**/

#include <algorithm>
#include <iostream>

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
}
