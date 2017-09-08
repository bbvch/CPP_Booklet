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

file(GLOB SOURCE_FILES source/*.cc)

foreach(CC_FILE ${SOURCE_FILES} )
  get_filename_component(SOURCE_BASENAME ${CC_FILE} NAME)
  string (REPLACE ".cc" "" EXE_NAME ${SOURCE_BASENAME})
  add_executable(${EXE_NAME} ${CC_FILE})
endforeach(CC_FILE ${SOURCE_FILES} )

find_program(PYTHON_PATH python)
if(PYTHON_PATH)
  add_custom_target(split_examples COMMAND python ${CMAKE_CURRENT_LIST_DIR}/separate_into_examples.py)
else()
  message(WARNING "Python not found, will not build target to separate examples")
endif()

#if vi improved is detected add a target for generating html output
find_program(VIM_PATH vim)


if(VIM_PATH)
  message("Vim found in ${VIM_PATH}")
  
  set(SOURCES_TO_CONVERT source/)
  configure_file(generate_html.cmake.in generate_html.cmake @ONLY)
 
#  add_custom_target(build_html 
#  COMMAND ${CMAKE_CURRENT_LIST_DIR}/generate_html.sh)
else()
  message(WARNING "Vim not found, will not add target to build html output")
endif()
