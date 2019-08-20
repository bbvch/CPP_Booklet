[![Build Status](https://travis-ci.com/bbvch/CPP_Booklet.svg?branch=master)](https://travis-ci.com/bbvch/CPP_Booklet)

These are examples illustrating the use of some of the C++11/14/17 features used in the [booklet about C++11/14/17 language](https://www.bbv.ch/de/booklet.html#die-neuen-c-standards-%E2%80%93-c-11-bis-c-17) (*german*) produced by [bbv software services](https://www.bbv.ch). [Read the booklet online](https://issuu.com/bbvsoftwareservices/docs/c__17_es?e=12228561/55697143) or [download it as pdf](https://www.bbv.ch/images/bbv/pdf/downloads/booklets/C++17_DS.pdf)

# Supported Compilers

 * g++ 7.0.1 - All examples compile and run
 * clang 5.0.0 and newer - All examples compile and run
 * MSVC 19.16 (Visual Studio 15 2017) - All examples compile and run
 

Tip: use  https://godbolt.org/ to test various other compilers


# Building with CMake
CMake will generate a makefile that will create an make target/executable for each *.cc file. At the moment (29. June 2017) only gcc 7.0.1 is C++17 feature complete. CMake will build makefiles for other compilers as well, but some examples will fail to compile.
To specify a non-default compiler (i.e. g++7) to use  `$CC` and `$CXX` environment variables or use `cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-7` to specify the compiler to use.

As soon as more and more compilers are able to compile the full C++17 feature set they will be added.
If you find one missing, raise an issue on github for it. https://github.com/bernedom/CPP_Booklet

See https://cmake.org/cmake/help/v3.8/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html for known compilation features of cmake.

## building and compiling
`$>cmake .`

`$>make`

Or 

`$>cmake .`

`$>cmake --build . --target all`

## Generating HTML output for examples
In order to link the examples in the .cc files to the printed version of the booklet the examples are annotated in code with ```\\@<number```
CMake will parse the .cc files in the 'src' folder for annotations for the example numbers in the print version of the booklet and split these files into files to create a syntax highlighted html file for each example. 

*Note* whenever a new example is annotated in a .cc file cmake needs to be run again to separate the files again. 
Alternatively the run ```separate_into_examples.py``` to split the files manually. 
To generate syntax highlighed html manually run `highlight_files.py -s <examples_dir> -t <target_dir>` (requires the ```pygments``` python package)

### building and compiling with non-feature complete compilers
As most make tools (GNU make, nmake) exit if a target fails to build additional options have to be passed to make to continue even on a failed target
for GNU make use `$>make -i` for nmake use `$>nmake -I` if using cmake to build use `$>cmake --build . --target all` 

### Including intentionally broken code
Some examples contain code that is intentionally to fail to compile. Usually this is done to illustrate some C++ feature. To compile the sources to allow for such failure use. Note the use of the -i flags else make stops on the first failure
`$>make clean`
`$>make CXX_FLAGS+=-DEXPECT_FAILED_COMPILATION -i`

Or if using cmake directly to build
`$>cmake --build . --target all -- CXX_FLAGS+=-DEXPECT_FAILED_COMPILATION -i` 

# Compiling by hand:
clang: `$>clang++ -std=c++1z file.cc -o file.exe`

g++: `$>g++ -std=c++17 file.cc -o file.exe`

use `$>clang++ -std=c++1z -S` to compile to assembler code

## Formatting:
All examples are formatted using clang-format
`$>clang-format -i file.cc` for formatting

