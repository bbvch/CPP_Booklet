/**
* Example for section 2.26
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
*  This example illustrates the definition of variable templates
*
* SPDX-License-Identifier: GPL-3.0
*
**/


//@53
template<typename T>
constexpr T pi = T(3.1415926535897932385);

auto two_pi = pi<float> * 2;
//@53

int main(int, char**)
{
return 0;
}

