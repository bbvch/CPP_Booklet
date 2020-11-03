/**
* Example for section 2.27
* of the C++ Booklet
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of initializer statements in selection
*statements
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char **argv) {
  std::srand(std::time(0));
//@40
  // initialize i with rand(); then perform the if
  if (int i = std::rand(); i % 2 == 0) {
    std::cout << "i is even" << std::endl;
  } else {
    std::cout << "i is odd" << std::endl;
  }

  // initialize i with rand(); then perform the switch
  switch (int i = std::rand(); i % 3) {
  case 0:
    std::cout << "i is a multiple of 3" << std::endl;
    break;
  case 1:
    std::cout << "i is not a multipe of 3" << std::endl;
    break;
  case 2:
    std::cout << "i is almost a multipe of 3" << std::endl;
    break;
  }
//@40
  return 0;
}
