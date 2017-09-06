/**
* Example for section 2.7
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
* This example illustrates the usage of static_asserts
*
* SPDX-License-Identifier: GPL-3.0
*
**/

//@18
static_assert((sizeof(long) == 8), "64 bit code not supported!");

template <typename T> struct Dummy {
  static_assert(sizeof(int) >= sizeof(T), "Dummy<T>: T is too small!");
};
//@18

int main(int, char **) {
//@18
  Dummy<int> di; // OK

#ifdef EXPECT_FAILED_COMPILATION
  Dummy<short> ds; // Assert on compile tile
#endif
//@18
}
