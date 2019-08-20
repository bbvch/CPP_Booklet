/**
* Example for section 2.22
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2020
*
*  This example illustrates the hexadecimal floating point literals
*
* SPDX-License-Identifier: GPL-3.0
*
**/

#include <iostream>

int main() {
//@47
  //binary literal
  int i = 0b1000;
//@47

//@48
  // implicitely cast to float
  float f = 0x1.2p3; // = decimal 1.125  or 1. + 1/16 * 2 * 2^3;

  // with f (or F) suffix to explicitly state it as a float
  float f1 = 0xA.1p3f;

  // = decimal 0.5 omitting value in front of decimal separator
  float f2 = 0x.1p3;

  // = decimal 80 omitting value after decimal separator
  float f3 = 0xA.p3;

  double d = 0xDEAD.D0D0p2;
  double d2 = 0xDEAD.D0D0p2l; // explicitly stating double
//@48

//@49
  // single quotation mark as digit separator. Has no effect on the interpretation
  int x = 1'222'333;
//@49
}
