/**
* Example for section 2.14
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
*  This example illustrates the use of constexpr for simple expressions
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <array>

//@26
constexpr double pi{
    3.1416}; // const floating point instead of a #define PI 3.1416
constexpr int square(int x) { return x * x; }

// constant expressions and functions can be used in arrays and simuliar
float fArray[square(5)];

// constant expressions can be used as template arguments
std::array<int, square(10)> arr;
struct Dummy {
  constexpr Dummy(int a, int b) : m_a(a), m_b(b) {}
  int m_a, m_b;
};

#ifdef EXPECT_FAILED_COMPILATION
// fails because 'new' is a non-const operation
constexpr Dummy *construct(int x, int y) { return new Dummy(x, y); }
#endif

constexpr Dummy d{3, 4};
// d.m_a is transformed to a constant expression 3
int iArray[d.m_a];
//@26
int main(int, char **) {}
