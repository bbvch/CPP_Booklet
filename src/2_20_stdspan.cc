/**
* Example for section 2.20
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of std span feature
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <vector>
#include <iostream>

#ifdef __has_include
  #if __has_include(<span>)
  #include <span>
  int main() {
      std::vector<std::string> greeting = {"hello", "world"};
      std::span<std::string> span (greeting);
      for(auto && s : span) {
          s[0] = std::toupper(s[0]);
      }
      // another name for span could be array_view
      for (const auto& word: greeting) {
          std::cout << word << ' ';
      }
  }
  #else

    #include <iostream>

    int main() {
      std::cout << "std::span not implemented yet!" << std::endl;
      return 1;
    }

  #endif  // __has_include(<filesystem>)
#endif  // __has_include
