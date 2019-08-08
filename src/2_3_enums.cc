/**
* Example for section 2.3
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* this examples illustrates the extended syntax available for enums since C++11
*
* SPDX-License-Identifier: GPL-3.0
*
**/

//@8
// non scoped enum
enum Color { Cyan, Magenta, Yellow, Black };
enum Sound { Beep, Bop, Boing };

// the keyword 'class' following 'enum' declares a scoped enum
enum class RGB { Red, Green, Blue, Black };
enum class CMY { Cyan, Magenta, Yello, Black };

// scoped enum with explicit type specifier
enum class Fruit : unsigned int { Apple, Pear };
//@8

#ifdef __cpp_using_enum
std::string GetFruitName(Fruit fruit) {
  switch (fruit) {
    using enum Fruit;     // ok with C++20
    case Apple:     return "Apple";
    case Pear:      return "Pear";
  }
}
#endif

int main(int, char **) {
//@8

  CMY cmy = CMY::Black; // CMY scope
  RGB rgb = RGB::Black; // RGB scope

  Color c1 = Cyan;        // ok
  Color c2 = Color::Cyan; // also ok
#ifdef EXPECT_FAILED_COMPILATION
  RGB red = Red; // Error unscoped assignement

  // Error, cross-scope comparison
  if (rgb == cmy) {
  }

#endif

  // Compiles with only a warning but is semantically incorrect
  if (Sound::Boing == Color::Yellow) {
  }

#ifdef __cpp_using_enum
  std::cout << "Apple and " << GetFruitName(Fruit::Pear) << std::endl;
#endif
//@8
}
