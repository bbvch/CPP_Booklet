/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

enum Color { Cyan, Magenta, Yello, Black };

enum class RGB { Red, Green, Blue, Black };
enum class CMY { Cyan, Magenta, Yello, Black };

int main(int, char **) {
  CMY cmy = CMY::Black; // CMY scope
  RGB rgb = RGB::Black; // RGB scope => OK
                        // if (rgb == cmy) {…} // Error, cross-enum Vergleiche
  // sind nicht erlaubt!
  enum class Fruits : unsigned int { Apples, Pears };

  Color c1 = Cyan;
  Color c2 = Color::Cyan;
}
