/**
* Example for section 2.14
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates ...
*
* SPDX-License-Identifier: GPL-3.0
*
**/

// ranges was not included yet..and has no feature test macro
 #if __cplusplus > 201908L

 #include <vector>
 #include <ranges>
 #include <iostream>

int main()
{

  std::vector<int> numbers{0,1,2,3,4,5};

  // create adaptor for even numbers
  auto even = [](int i){ return 0 == i % 2; };

  // create adaptor for squaring numbers
  auto square = [](int i) { return i * i; };

  // just plug in and combine adaptors as necessary
  for (int i : ints | std::view::filter(even) | std::view::transform(square)) {
    std::cout << i << ' ';

    // output is 0 4 16
  }

  return 0;
}

#endif
