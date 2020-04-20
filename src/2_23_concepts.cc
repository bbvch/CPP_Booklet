/**
* Example for section 2.24
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of concepts for template programming
*
* SPDX-License-Identifier: GPL-3.0
*
**/
#ifdef __cpp_concepts


#include <algorithm>
#include <concepts>
#include <iostream>
#include <type_traits>

/*
    following 3 examples show how concepts are defined:
    template <typename T>
    concept concept-name = constexpr expression;

*/
// T must be const
template <typename T>
concept Constant = std::is_const<T>::value;

// T must have the same alignment as int
template <typename T>
concept Alignment_Int = std::alignment_of_v<T>
                        == std::alignment_of<int>();

// T must be a signed integral
template<class T>
concept SignedIntegral = std::is_integral_v<T>
      && std::is_signed_v<T>;

/*
    Following 3 different notations show the appications
    of a concept. The last one does not use requires,
    instead the concept-name for typename
*/
// Requires Constraint
template <typename Register>
	requires Alignment_Int<Register>
void CopyTo(Register & reg);

// Trailing Requires Constraint
template <typename Value>
void UpdateValue(Value& val) requires Constant<Value>;

// Constrained Template Parameter
template<SignedIntegral Position>
void MoveRelative(Position& target);

/*
    Following a concept which specifies the auto-placeholder;
    this enables to use auto as both return value and argument
*/
// Abbreviated Function Template
SignedIntegral auto Clamp(SignedIntegral auto min, SignedIntegral auto max, SignedIntegral auto val)
{
	return std::max(std::min(max, val), min);
}

/*
	Following is a definition of the concept Number which requires a set of operators

	*Note" that each operator requires a concept itself!
	*Note" i.e. { expression } -> concept;
*/
template<typename T>
concept Number = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
    { a / b } -> std::convertible_to<T>;
    { -a }    -> std::convertible_to<T>;
    { a += b } -> std::convertible_to<T>;
    { a -= b } -> std::convertible_to<T>;
    { a *= b } -> std::convertible_to<T>;
    { a /= b } -> std::convertible_to<T>;
    { T{0}};
};

/*
    Following defines an abbreviated function template (see above)
*/
Number auto AddTwoNumbers(const Number auto a, const Number auto b)
{
  return a + b;
}

int main()
{

	int min_s = -100; int max_s = 100; int val_s = 123;
	std::cout << "Clamp [int, int, int] " << Clamp(min_s, max_s, val_s) << std::endl;


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

  // Clamp is defined to only work with signed numbers thus the following use of unsigned int breaks the concept
  unsigned int min_us = 0; unsigned int max_us = 100; unsigned int val_us = 123;
  std::cout << "Clamp [unsigned int, unsigned int, unsigned int] " << Clamp(min_us, max_us, val_us) << std::endl;
#endif

  return 0;
}

#else

  #include <iostream>

  int main() {
    std::cout << "concepts not implemented yet!" << std::endl;
    return 1;
  }

#endif  // __cpp_concepts
