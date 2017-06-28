/**
* Example for section @section @title
* of the C++ Booklet (https://goo.gl/VJ4T3A)
* published by bvv software services AG (c) 2017
*
**/

#if __has_include(<unistd.h>)
#define OPEN_SHARDED dlopen
#elif __has_include(<windows.h>)
#define OPEN_SHARED LoadLibrary
#else
#pragma error("loading shared libraries not supported");
#endif

int main(int, char **) {}