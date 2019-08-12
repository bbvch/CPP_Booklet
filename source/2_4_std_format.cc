/**
* Example for section 2.6
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#ifdef __cpp_lib_format

#include <format>

int main(){
    std::string s0 = std::format("{}", 42);                      // s0 == "42"
    std::string s1 = std::format("{0:b} {0:d} {0:o} {0:x}", 42); // s1 == "101010 42 52 2a"
    std::string s2 = std::format("{0:#x} {0:#X}", 42);           // s2 == "0x2a 0X2A"
    return 0;
}

#endif
