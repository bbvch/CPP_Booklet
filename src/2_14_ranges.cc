/**
* Example for section 2.14
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of the ranges library introduced with C++20
*
* SPDX-License-Identifier: GPL-3.0
*
**/

// ranges was not included yet..and has no feature test macro
#ifdef __has_include
#if __has_include (<ranges>)
 #include <functional>
 #include <map>
 #include <vector>
 #include <ranges>
 #include <iostream>

int main()
{

  // create adaptor for even numbers
  auto even = [](int i){ return 0 == i % 2; };

  // create adaptor for squaring numbers
  auto square = [](int i) { return i * i; };

  // just plug in and combine adaptors as necessary
  for (int i : std::views::iota(0, 5) | std::views::filter(even)
   	   	   	   	   	   	   	   	      | std::views::transform(square)) {
    std::cout << i << ' ' << std::endl;

    // output is 0 4 16
  }

  /*
   * Get the first 12 Fibonacci Numbers
   */
  std::function<int(int)> fibo;
  fibo = [&fibo] (int i) -> int { return i > 1? i* fibo(i-1) : 1;};

  for(int i: std::views::iota(0) | std::views::transform(fibo)
								| std::views::take(12))
  {
      std::cerr << i << std::endl;
  }

  /*
   * Get all people with big feet
   *
   */

  std::map <std::string, unsigned int> people_shoe_size_map = {
          {"Alf", 40},
          {"SuzyQ", 36},
          {"Alain", 42},
          {"Luci Fer", 37},
          {"Christian", 47}
      };

  auto bigfoot = [] (const std::pair<std::string, unsigned int>& people_shoe) { return people_shoe.second > 46; };
  for(const auto& el : people_shoe_size_map
                     | std::views::filter(bigfoot))
  {
     std::cout << el.first << " has size " << el.second << std::endl;
  }

  return 0;
}

#else

  #include <iostream>

  int main() {
    std::cout << "ranges not implemented yet!" << std::endl;
    return 1;
  }

#endif  // __has_include(<ranges>)
#endif  // __has_include
