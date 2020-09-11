/**
* Example for section 2.32.1
* of the C++ Booklet
* published by bbv software services AG (c) 2020
*
*  This example illustrates the definition of variable templates
*
* SPDX-License-Identifier: GPL-3.0
*
**/


//@52
template<typename T>
constexpr T pi = T(3.1415926535897932385);

auto two_pi = pi<float> * 2;
//@52

int main(int, char**)
{
return 0;
}
