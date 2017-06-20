All examples tested and compiled with clang 3.9 and g++ 7.1 using https://godbolt.org/ 


Compiling:
	clang: $>clang++ -std=c++1z file.cc -o file.exe
	g++: $>g++ -std=c++17 file.cc -o file.exe

other comments:
use '$>clang-format -i file.cc' for formatting

use '$>clang++ -std=c++1z -S' to compile to assembler code
