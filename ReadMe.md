All examples tested and compiled with clang 3.9 and g++ 7.1 using https://godbolt.org/ 

# Cmake 
The CMakeLists.txt file will genreate an executable for each *.cc file 
## rebuilding the CMakeLists 
execute generate_cmakelists.sh in a bash shell to rebuild the cmakelist file


# Compiling:
	clang: $>clang++ -std=c++1z file.cc -o file.exe
	g++: $>g++ -std=c++17 file.cc -o file.exe
	
	use '$>clang++ -std=c++1z -S' to compile to assembler code

## Formatting:
	use '$>clang-format -i file.cc' for formatting


