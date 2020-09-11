/**
* Example for section 2.32
* of the C++ Booklet
* published by bbv software services AG (c) 2020
*
* This exmaple illustrates the use of the __has_include preprocessor directive
*
* SPDX-License-Identifier: GPL-3.0
*
**/

//@50
#if __has_include(<unistd.h>)
#define OPEN_SHARDED dlopen
#elif __has_include(<windows.h>)
#define OPEN_SHARED LoadLibrary
#else
#pragma error("loading shared libraries not supported");
#endif
//@50

int main(int, char **) {}
