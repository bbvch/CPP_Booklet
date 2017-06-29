These are examples illustrating the use of some of the C++11/14/17 features used in the [booklet about C++11/14/17 language](https://www.bbv.ch/de/index.php/?option=com_content&view=article&id=186&Itemid=361#c-11-14-sprach-und-standard-library-erweiterungen) (*german*) produced by bbv software services

# Supported Compilers

 * g++ 7.0.1 - All examples compile and run
 * MSVC 14.1 (Visual Studio 2017) - C++14 complete, missing most of the C++17 features 
 * clang 3.9 - C++14 complete but missing a few C++17 features
 

Tip: use  https://godbolt.org/ to test various other compilers


# Building with CMake
CMake will generate a makefile that will genreate an make target/executable for each *.cc file. At the moment (29. June 2017) only gcc 7.0.1 is C++17 feature complete. CMake will build makefiles for other compilers as well, but some examples will fail to compile.
To specify a non-default compiler (i.e. g++7) to use  `$CC` and `$CXX` environment variables or use `cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-7` to specify the compiler to use.

As soon as more and more compilers are able to compile the full C++17 feature set they will be added.
If you find one missing, raise an issue on github for it. https://github.com/bernedom/CPP_Booklet

## building and compiling
'$>cmake .'
'$>make

Or 
'$>cmake .
'$>cmake --build . --target all 

### building and compiling with non-feature complete compilers
As most make tools (GNU make, nmake) exit if a target fails to build additional options have to be passed to make to continue even on a failed target
for GNU make use '$>make -i' for nmake use '$>nmake -I' if using cmake to build use '$>cmake --build . --target all 

### Including intentionally broken code
Some examples contain code that is intentionally to fail to compile. Usually this is done to illustrate some C++ feature. To compile the sources to allow for such failure use. Note the use of the -i flags else make stops on the first failure
'$>make clean
'$>make CXX_FLAGS+=-DEXPECT_FAILED_COMPILATION -i

Or if using cmake directly to build
'$>cmake --build . --target all -- CXX_FLAGS+=-DEXPECT_FAILED_COMPILATION -i 

## rebuilding the list of targets 
execute generate_cmakelists.sh in a bash shell to rebuild the list of files to compile 

# Compiling by hand:
clang: `$>clang++ -std=c++1z file.cc -o file.exe`
g++: `$>g++ -std=c++17 file.cc -o file.exe`

use `$>clang++ -std=c++1z -S` to compile to assembler code

## Formatting:
All examples are formatted using clang-format
`$>clang-format -i file.cc` for formatting


