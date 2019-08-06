cmake_minimum_required(VERSION 3.12)
project("CPP_Booklet"
        VERSION 1.0.0
        DESCRIPTION "C++ source files for the CPP booklet from bbv"
        HOMEPAGE_URL "https://github.com/bbvch/CPP_Booklet")

# this is a workaround because MSVC is a CMake internal variable which leads to
# confusion when doing STREQUAL on it
set(MSVC_COMPILER_NAME "MSVC")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("Compiler is: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "7.0.1")
    message(
      WARNING "Insufficient g++ version - use 7.0.1 to compile all examples")
  endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES "^clang.*"
       OR CMAKE_CXX_COMPILER_ID MATCHES "^Clang.*")

  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.0.0")
    message(
      WARNING
        "Insufficient clang version - use 4.0.0 or above to compile all examples"
      )
  endif()
else()
  message(
    WARNING
      "your compiler is not yet able to compile all examples under the C++17 standard, some compilations may fail"
    )
endif()

set(SOURCE_DIR src)
file(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cc)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES html)

foreach(CC_FILE ${SOURCE_FILES})

  get_filename_component(SOURCE_BASENAME ${CC_FILE} NAME)
  string(REPLACE ".cc"
                 ""
                 EXE_NAME
                 ${SOURCE_BASENAME})
  add_executable(${EXE_NAME} ${CC_FILE})
  set_target_properties(${EXE_NAME}
                        PROPERTIES CXX_STANDARD
                                   17
                                   CXX_STANDARD_REQUIRED
                                   YES)
endforeach(CC_FILE ${SOURCE_FILES})

# if vi improved is detected add a target for generating html output
find_program(VIM_PATH vim)

if(VIM_PATH)
  message("Vim found in ${VIM_PATH}")

  find_program(PYTHON_EXECUTABLE python)

  # if Python is available the .cc files will be split into chunks for each
  # example in the print version of the booklet. The newly generated files will
  # be appended to the source list to generate the build_html targets once
  # caveat is that if new examples are added/configured in existing files cmake
  # needs to be run again
  if(PYTHON_EXECUTABLE)
    message("found Python; Splitting cc files into individual examples")
    execute_process(COMMAND ${PYTHON_EXECUTABLE}
                            ${CMAKE_CURRENT_LIST_DIR}/separate_into_examples.py)
    file(GLOB SOURCE_FILES_EXAMPLES examples/*.cc)
    set(SOURCE_FILES ${SOURCE_FILES} ${SOURCE_FILES_EXAMPLES})

  else()
    message(
      WARNING "Python not found, will not build target to separate examples")
  endif()

  configure_file(generate_html.cmake.in ${CMAKE_BINARY_DIR}/generate_html.cmake
                 @ONLY)
  include(${CMAKE_BINARY_DIR}/generate_html.cmake)

else()
  message(WARNING "Vim not found, will not add target to build html output")
endif()
