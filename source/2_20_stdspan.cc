/**
* Example for section 2.20
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates ...
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <vector>
#include <span>
#include <iostream>

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
