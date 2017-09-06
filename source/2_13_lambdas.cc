/**
* Example for section 2.13
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the usage of lambda functions
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <algorithm>
#include <vector>

int main(int, char **) {
//@24
  // declaration of a lambda function
  const auto square = [](int x) { return x * x; };
  // execution of the lambda above
  const auto r = square(4);

  // the parameter brackes () can be omitted if  empty set
  const auto abbreviated = [] { return 55; };

  // using auto a parameter types for even more generic programming
  const auto auto_param_function = [](const auto &a, const auto &b) {
    return a * b;
  };
//@24

//@25
  int x, y, z;

  const auto no_capture = []() {};           // No variables are acptured
  const auto capture_by_value = [x, y]() {}; // x and y are captured by value
  const auto capture_by_ref = [&x, &y]() {
  }; // x and y are captured by reference
  const auto mixed_capture = [x, &y, &z]() {}; // mixed captures

  // captures all variables in scope by value (square, r, x,y,z)
  const auto capture_all_by_value = [=]() {};
  // all variables in scope by reference
  const auto capture_all_by_ref = [&]() {};

  // all variables in scope by value, except x which is captured by reference
  const auto capture_all_by_value_except = [=, &x]() {};

  // capture all by reference except x
  const auto capture_all_by_ref_except = [&, x]() {};

  // initialized lambda captures
  auto init_function = [&r = x, x = x + 1 ]()->int {
    r += 2;
    return x + 2;
  };
//@25

//@26
  // using lambda with std::-functions
  std::vector<int> a1{1, 2, 3, 4, 5};
  std::vector<int> a2(a1.size());
  // fills a vector with the squares of the valus of another vectoir
  std::transform(a1.begin(), a1.end(), a2.begin(), square);

  // same but with explicit trailing return type
  std::transform(a1.begin(), a1.end(), a2.begin(),
                 [](int x) -> int { return x * x; });

  std::vector<int> v{1, 2, 3, 4, 5};
  int sum{0};
  // sums up the values of vector v using pass by reference for sum
  std::for_each(v.begin(), v.end(), [&sum](int i) { sum += i; });
//@26
}
