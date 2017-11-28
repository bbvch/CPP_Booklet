/**
* Example for section 2.8
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bbv software services AG (c) 2017
*
*
* SPDX-License-Identifier: GPL-3.0
*
**/

//@18
// this is how NULL used to be defined. NULL was never a language keyword, but
// always a predefined macro
#define NULL 0

void foo(const char *dummy) {

  if (dummy == nullptr) {
    // do something
  }
}
void foo(int i) {}

void bar(const char *c) {}
void bar(const float *f) {}

int main(int, char **) {

  const char *dummy = nullptr; // OK
#ifdef EXPECT_FAILED_COMPILATION
  // error, except if direct initialisation enabled during compilation
  bool valid = nullptr;
  int value = nullptr; // Error, assigning a pointer type to int
#endif
  int anInt{42};
  int *ptrTo_anInt = &anInt;
  ptrTo_anInt = nullptr; // OK

  foo(NULL);    // calls foo(int)
  foo(nullptr); // calls foo(const char*), because it matches the ptr type

#ifdef EXPECT_FAILED_COMPILATION
  bar(nullptr); // ambigous call to bar(const int*) or bar(const float*)
#endif
  bar(static_cast<const float *>(nullptr)); // force pointer type
}
//@18
