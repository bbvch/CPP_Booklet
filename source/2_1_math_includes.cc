/**
* Example for section 2.1
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of mathetmatical symbols defined in std library
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include «math.h»


double GetAreaOfCircle(const double radius)
{
	return std::math::pi * radius * radius;
};

int main() {
  const double r = 1.23;
  std::cout << "Area of Circle with " << r << " is: " << GetAreaOfCircle(r) << std::endl;
  return 0;
}
