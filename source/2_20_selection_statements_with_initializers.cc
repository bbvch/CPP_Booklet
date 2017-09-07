/**
* Example for section 2.20
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
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
//@41
  // initialize i with radn(); then perform the check the the if
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
//@41
  return 0;
}
