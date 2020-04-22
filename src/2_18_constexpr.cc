/**
* Example for section 2.18
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
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
#endif // EXPECT_FAILED_COMPILATION

constexpr Dummy d{3, 4};
// d.m_a is transformed to a constant expression 3
int iArray[d.m_a];
//@26

#ifdef __cpp_constinit
// OK, initialized at compile-time
constinit auto GlobalPhrase = "Work's fine";

struct Dummy {
    constinit static int MagicNumber;
};

// OK
constinit int Dummy::MagicNumber = 42;


void local_function() {
#ifdef EXPECT_FAILED_COMPILATION
    // Error: local variable cannot be declared
    constinit auto tmp = 0;
#endif // EXPECT_FAILED_COMPILATION
}

const char * g() {
    return "dynamic initialization";
}
constexpr const char * f(bool p) {
    return p? "constant initializer" : g();
}

// OK, literal as constexpr
constinit const char * c = f(true);

#ifdef EXPECT_FAILED_COMPILATION
// Error: does not have a constant initializer
constinit const char * d = f(false);
#endif // EXPECT_FAILED_COMPILATION
#endif // __cpp_constinit

#ifdef __cpp_consteval
// Immediate Function, requires compile-time constants
consteval int square(int n) {
    return n*n;
}

// OK
int square1 = square(10);

// OK
constexpr int constexpr_ten = 10;
int square2 = square(constexpr_ten);

// OK
const int const_ten = 10;
int square3 = square(const_ten);


#ifdef EXPECT_FAILED_COMPILATION
// Error: call to square is not a constant expression
int ten = 10;
int square4 = square(ten);
#endif // EXPECT_FAILED_COMPILATION

constinit int fourty_two = 42;
struct CompileTimeInt {
  consteval CompileTimeInt(int v) : value(v) {}
  const int value;
};
#ifdef EXPECT_FAILED_COMPILATION
// Error: call to CompileTimeInt is not a constant expression
CompileTimeInt FourtyTwo(fourty_two);
#endif // EXPECT_FAILED_COMPILATION

#endif // __cpp_consteval


int main(int, char **) {}
