#include <iostream>

int main()
{
    float f = 0x1.2p3; // = decimal 1.125  or 1. + 1/16 * 2 * 2^3; implicitely cast to float
    float f1 = 0xA.1p3f; // with f (or F) suffix to explicitely state it as a float
    float f2 = 0x.1p3; // = decimal 0.5 omitting value in front of decimal separator
    float f3 = 0xA.p3; // = decimal 80 omitting value after decimal separator

    double d = 0xDEAD.D0D0p2;
    double d2 = 0xDEAD.D0D0p2l; // explicitely stating

}
