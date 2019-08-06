/**
* Example for section 2.9 
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* this example illustrates the use of right angle brackets
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <vector>

//@19
template<bool T>
class SomeType 
{

};
//@19

int main(int, char**)
{
//@19
	//OK before and after C++11. Note the space between the  >>
	std::vector<std::pair<int, int> > vec0;
	
	//OK only after C++11
	std::vector<std::pair<int, int>> vec1;
	
	//OK after C++11: interpreted as std::vector<SomeType<false>>
	std::vector<SomeType<(1>2)>> vec3;
//@19
}
