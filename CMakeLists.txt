cmake_minimum_required (VERSION 2.6)
project (CPP_Booklet)

#this is a workaround because MSVC is a CMake internal variable which leads to confusion
#when doing STREQUAL on it
set(MSVC_COMPILER_NAME "MSVC")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("Compiler is: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "7.0.1")
    message(WARNING "Insufficient g++ version - use 7.0.1 to compile all examples")
  endif()	
  add_compile_options(-std=c++17)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "clang")
  add_compile_options(-std=c++1z)
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.0.0")
	message(WARNING "Insufficient clang version - use 4.0.0 or above to compile all examples")
  endif()
else()
  message(WARNING "your compiler is not yet able to compile all examples under the C++17 standard, some compilations may fail")
endif()

include(executable_list.cmake)

