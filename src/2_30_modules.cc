/**
* Example for section 2.31
* of the C++ Booklet
* published by bbv software services AG (c) 2020
*
*  This example illustrates ...
*   NOTE: should be compiled with -std=c++2a -fmodules
*
* SPDX-License-Identifier: GPL-3.0
*
**/


#ifdef __cpp_modules

// at given time frame partial modules were not implemented yet
import std;

int main(){
  std::cout << "std.io module already loaded!" << std::endl;
  return 0;
}

#else

  #include <iostream>

  int main() {
    std::cout << "modules not implemented yet!" << std::endl;
    return 1;
  }

#endif
