/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
* This example illustrates the usage of variadic templates
**/

#include <iostream>

struct Dummy {
  int x;
  char c;
};

// variadic template function definition
template <typename... Args> void aFunction(Args... args) {

}

// variadic template class definition
template <typename... Args> class aClass {

};

int sum() { return 0; } // End of recursion
template <typename T, typename... US> int sum(T t, US... us) {
  return t + sum(us...); // recursion popping the first template argument
}
template <typename... US> int sumSquares(US... us) {
  return sum(us * us...); // calls sum<typename T, typename ...US>
}

int main(int, char **) {
  aFunction(42, 1.14159, "Hello", Dummy());
  aFunction(1, 2, 3, 4, 5);

  aClass<std::string, int> ac1;
  aClass<char, char, double, std::string> ac2;
  aClass<> ac3;

  std::cout << sumSquares(1) << std::endl;
  std::cout << sumSquares(1, 2) << std::endl;
  std::cout << sumSquares(1, 2, 3) << std::endl;
}
