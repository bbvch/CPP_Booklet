/**
* Example for section 2.1
* of the C++ Booklet
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of mathematical symbols defined in std library
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#ifdef __has_include

#include <iostream>
#if __has_include(<numbers>)
#include <numbers>

	double GetAreaOfCircle(const double radius)
	{
		return std::numbers::pi * radius * radius;
	};

	int main() {
	const double r = 1.23;
	std::cout << "Area of Circle with Radius " << r << " is: " << GetAreaOfCircle(r) << std::endl;
	    return 0;
	}

#else

	int main() {
	    std::cout << "Could not include std::numbers" << std::endl;
	    return 1;
	}

#endif	// __has_include(<numbers.h>)
#endif	// __has_include
