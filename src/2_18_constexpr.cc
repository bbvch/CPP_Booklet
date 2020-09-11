/**
* Example for section 2.18
* of the C++ Booklet
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

// constant expressions and functions can be used in arrays and similar
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

constexpr Dummy dy{3, 4};
// d.m_a is transformed to a constant expression 3
int iArray[dy.m_a];
//@26

#ifdef __cpp_constinit
// OK, initialized at compile-time
constinit auto GlobalPhrase = "Work's fine";

struct Magic {
    constinit static int Number;
};

// OK
constinit int Magic::Number = 42;


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
consteval int square_consteval(int n) {
    return n*n;
}

// OK
int square1 = square_consteval(10);

// OK
constexpr int constexpr_ten = 10;
int square2 = square_consteval(constexpr_ten);

// OK
const int const_ten = 10;
int square3 = square_consteval(const_ten);


#ifdef EXPECT_FAILED_COMPILATION
// Error: call to square is not a constant expression
int ten = 10;
int square4 = square_consteval(ten);
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
