/**
* Example for section 2.10
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This exampple illustrates the use of a range based for loop
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <vector>

int main(int, char **) {
//@20
  int iArray[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  // access the elements by value
  for (int i : iArray) {
    // do something
  };

  std::vector<int> v{1, 2, 3, 4};

  // access the elements as references
  for (const auto &i : v) {
    // do something
  }
//@20
}
