cmake_minimum_required (VERSION 2.6)
project (CPP_Booklet)

#this is a workaround because MSVC is a CMake internal variable which leads to confusion
#when doing STREQUAL on it
set(MSVC_COMPILER_NAME "MSVC")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("Compiler is: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "7.0.0")
    message(FATAL_ERROR "Insufficient gcc version")
  endif()	
  add_compile_options(-std=c++17)
else()
  message(WARNING "your compiler is not yet able to compile all examples underthe C++17 standard, some compilations may fail")
endif()

include(executable_list.cmake)

