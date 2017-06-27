cmake_minimum_required (VERSION 2.6)
project (CPP17_Snippets)


if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
 if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "7.1.0")
    message(FATAL_ERROR "Insufficient gcc version")
  endif()	
  add_compile_options(-std=c++17)
else()
	message(FATAL_ERROR "Only GCC 7.1.0 and above supported")
endif()

include(executable_list.cmake)

