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

class Circle {
public:
    Circle(float r) : radius(r) {};
    float GetRadius() { return radius; };
    std::partial_ordering operator<=> (Circle& rhs) {
      // just compare by radius
        return radius <=> rhs.GetRadius();
    }
private:
    float radius;
};

class Rectangle {
public:
    Rectangle(unsigned int a, unsigned int b) : length(a), width(b) {};
    unsigned int GetArea() { return length * width; };

    std::weak_ordering operator<=> (Rectangle& rhs) {
        return GetArea()<=>rhs.GetArea();
    };
private:
    unsigned int length;
    unsigned int width;
};

int main(int, char **) {
  Circle circle_a(1/3.14);
  Circle circle_b(1.234);
  std::cout << "Comparing Two Circles a and b: \n" << std::endl;
  std::cout << " a <=> b : " << circle_a <==> circle_b << std::endl;

  Rectangle rectangle_a(4,6);
  Rectangle rectangle_b(6,4);
  std::cout << "Comparing Two Rectangles a and b: \n" << std::endl;
  std::cout << " a <=> b : " << rectangle_a <==> rectangle_b << std::endl;

  return 0;
}

#else

  #include <iostream>

  int main() {
    std::cout << "three-way-comparison not implemented yet!" << std::endl;
    return 1;
  }

#endif  // __cpp_impl_three_way_comparison
