/**
 * Example for section 2.8
 * of the C++ Booklet
* published by bbv software services AG (c) 2020
 *
 * This example illustrates the usage of static_asserts
 *
 * SPDX-License-Identifier: GPL-3.0
 *
 **/

//@17
#ifdef EXPECT_FAILED_COMPILATION
static_assert((sizeof(long) == 8), "64 bit code not supported!");
#endif

template <typename T> struct Dummy {
    static_assert(sizeof(int) >= sizeof(T), "Dummy<T>: T is too small!");
};
//@17

int main(int, char **) {
  //@17
  Dummy<int> di; // OK

#ifdef EXPECT_FAILED_COMPILATION
  Dummy<short> ds; // Assert on compile tile
#endif
  //@17
}
