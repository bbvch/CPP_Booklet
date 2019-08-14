/**
* Example for section 2.31
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates ...
*   NOTE: should be compiled with -std=c++2a -fmodules
*
* SPDX-License-Identifier: GPL-3.0
*
**/


#ifdef _­_­cpp_­modules

// at given time frame partial modules were not implemented yet
import std;

int main(){
  std::cout << "std.io module already loaded!" << std::endl;
  return 0;
}
#endif
