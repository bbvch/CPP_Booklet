/**
* Example for section 2.10
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the use of the three-way-comparison operator <=>
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#ifdef __cpp_impl_three_way_comparison

#include <compare>
#include <iostream>

struct Circle {
public:
    Circle(float r) : radius(r) {};
    std::partial_ordering operator<=> (Circle& rhs) {
        // compare by radius
        return radius <=> rhs.radius;
    }
    float radius;
};

struct Rectangle {
   Rectangle(int length, int height) : a(length), b(height), area(a*b){ };
   const int a;
   const int b;
   const int area;
	std::weak_ordering operator<=>( const  Rectangle &rhs)
   {
       if(a <=> rhs.a != 0
       && b <=> rhs.b != 0
       && area <=> rhs.area == 0)
       {
           return std::weak_ordering::equivalent;
       }
       return a <=> rhs.a;
   }
};

struct ClassWithLotsOfMembers {
	// usually a definition to compare all members would be
	// necessary, simplified with operator <=> as default
	auto operator<=>(const ClassWithLotsOfMembers &rhs) const = default;
	// can now be compared by ==, !=, <=, >=, <, >
};


int main(int, char **) {
  Circle circle_a(1.42f);
  Circle circle_b(1.23f);

  std::cout << std::boolalpha;
  std::cout << "Comparing Two Circles a and b: \n" << std::endl;
  std::cout << " a <=> b  > 0: " << (circle_a <=> circle_b > 0) << std::endl;


  Rectangle rectangle_a(4,6);
  Rectangle rectangle_b(6,4);
  std::cout << "Comparing Two Rectangles a and b: \n" << std::endl;
  std::cout << " a <=> b : " << (rectangle_a <=> rectangle_b == 0) << std::endl;

  return 0;
}

#else

  #include <iostream>

  int main() {
    std::cout << "three-way-comparison not implemented yet!" << std::endl;
    return 1;
  }

#endif  // __cpp_impl_three_way_comparison
