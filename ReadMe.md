These are examples illustrating the use of some of the C++11/14/17 features used in the booklet about C++11/14/17 language produced by bbv software services 
https://www.bbv.ch/de/index.php/?option=com_content&view=article&id=186&Itemid=361#c-11-14-sprach-und-standard-library-erweiterungen

All examples tested and compiled with g++ 7.1 
(you can use  https://godbolt.org/)


# Building with CMake
CMake will generate a makefile that will genreate an executable for each *.cc file. At the moment (27. June 2017) only gcc 7.1.0 is C++17 feature complete, so CMake will only genreate makefiles if gcc 7.1.0 or newer is available. 
set the $CC and $CXX environment variables to specify the compiler to use. As soon as more and more compilers are abel to compile the full C++17 feature set they will be added. 
If you find one missing, raise an issue on github for it. https://github.com/bernedom/CPP17_Snippets

## rebuilding the list of targets 
execute generate_cmakelists.sh in a bash shell to rebuild the list of files to compile 


# Compiling by hand:
	clang: $>clang++ -std=c++1z file.cc -o file.exe
	g++: $>g++ -std=c++17 file.cc -o file.exe
	
	use '$>clang++ -std=c++1z -S' to compile to assembler code

## Formatting:
	use '$>clang-format -i file.cc' for formatting


