/**
* Example for section ...
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates ...
*
* SPDX-License-Identifier: GPL-3.0
*
**/

 #ifdef __cpp_concepts

 #include <iostream>
 #include <type_traits>   // should include concepts

 template<typename T>
 concept bool Number = requires(T a, T b) {
     { a + b } -> T;
     { a - b } -> T;
     { a * b } -> T;
     { a / b } -> T;
     { -a }    -> T;
     { a += b } -> T;
     { a -= b } -> T;
     { a *= b } -> T;
     { a /= b } -> T;
     { T{0}};
 };

 Number AddTwoNumbers(const Number a, const Number b)
 {
   return a + b;
 }

int main()
{
  // It's working with types int, float, char, bool
  std::cout << "AddTwoNumbers: 1 + 1: "         << AddTwoNumbers(1, 1) << std::endl;
  std::cout << "AddTwoNumbers: 3.14 + 0.77: "   << AddTwoNumbers(3.14, 0.77) << std::endl;
  std::cout << "AddTwoNumbers: 'a' + 'b': "     << AddTwoNumbers('a', 'b') << std::endl;
  std::cout << "AddTwoNumbers: true + false: "  << AddTwoNumbers(true, false) << std::endl;

#ifdef EXPECT_FAILED_COMPILATION
// It's not working with std::string (and also won't with const char* either)
/* Compiler Error:
  note:   constraints not satisfied
  // ...
  note: the required expression '(a - b)' would be ill-formed
  note: the required expression '(a * b)' would be ill-formed
  // ...
*/
  std::string left = "The answer is";
  std::string right = "FourtyTwo!";
  std::cout << "AddTwoNumbers: 'The answer is' + 'FourtyTwo!': " << AddTwoNumbers(left, right) << std::endl;
#endif

  return 0;
}

#endif
