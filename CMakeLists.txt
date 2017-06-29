cmake_minimum_required (VERSION 2.6)
project (CPP_Booklet)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("Compiler is: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
 if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "7.0.0")
    message(FATAL_ERROR "Insufficient gcc version")
  endif()	
  add_compile_options(-std=c++17)
else()
	message(FATAL_ERROR "Only GCC 7.0.1 and above supported")
endif()

include(executable_list.cmake)

