cmake_minimum_required(VERSION 3.12)
project("CPP_Booklet"
        VERSION 1.1.0
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

elseif(CMAKE_CXX_COMPILER_ID MATCHES "^[cC]lang.*")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "5.0.0")
    message(
      WARNING
        "Insufficient clang version - use 5.0.0 or above to compile all examples"
      )
  elseif(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "8.0.0")
    set(ENABLE_CPP20_FEATURES TRUE)
  endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "^AppleClang.*")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "10.0")
    message(
      WARNING
        "Insufficient AppleClang version - use 10.0 or above to compile all examples"
      )

  endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES "${MSVC_COMPILER_NAME}")
  message(WARNING "Insufficient msvc version ${CMAKE_CXX_COMPILER_VERSION}")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19.16")
    message(
      WARNING
        "Insufficient MSCV version - use 16.16 or above to compile all examples"
      )
  endif()
else()
  message(
    WARNING
      "your compiler is not yet able to compile all examples under the C++17 standard, some compilations may fail"
    )
endif()

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES html)

add_executable(2_13_range_based_for_loops src/2_13_range_based_for_loops.cc)
target_compile_features(2_13_range_based_for_loops PRIVATE cxx_range_for)

add_executable(2_15_nested_namespace_definitions
               src/2_15_nested_namespace_definitions.cc)
target_compile_features(2_15_nested_namespace_definitions PRIVATE cxx_std_17)

add_executable(2_16_trailing_return_types src/2_16_trailing_return_types.cc)
target_compile_features(2_16_trailing_return_types PRIVATE
                        cxx_trailing_return_types)

add_executable(2_17_lambdas src/2_17_lambdas.cc)
target_compile_features(2_17_lambdas
                        PRIVATE
                        cxx_lambdas
                        cxx_generic_lambdas)

add_executable(2_17_this_as_lambda_capture src/2_17_this_as_lambda_capture.cc)
target_compile_features(2_17_this_as_lambda_capture
                        PRIVATE
                        cxx_lambdas
                        cxx_generic_lambdas
                        cxx_std_17)
target_compile_options(2_17_this_as_lambda_capture
                       PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>)

add_executable(2_18_1_constexpr_lambda src/2_18_1_constexpr_lambda.cc)
# needs cxx_std_17 because passing this as capture is not available else
target_compile_features(2_18_1_constexpr_lambda
                        PRIVATE
                        cxx_lambdas
                        cxx_generic_lambdas
                        cxx_constexpr
                        cxx_std_17)
target_compile_options(2_18_1_constexpr_lambda
                       PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>)

add_executable(2_18_constexpr src/2_18_constexpr.cc)
target_compile_features(2_18_constexpr PRIVATE cxx_constexpr)

add_executable(2_18_constexpr_if src/2_18_constexpr_if.cc)
target_compile_features(2_18_constexpr_if
                        PRIVATE
                        cxx_constexpr
                        cxx_std_17)
target_compile_options(2_18_constexpr_if
                       PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>)

add_executable(2_19_alignment src/2_19_alignment.cc)
target_compile_features(2_19_alignment
                        PRIVATE
                        cxx_alignas
                        cxx_alignof)

add_executable(2_21_move_semantics src/2_21_move_semantics.cc)
target_compile_features(2_21_move_semantics PRIVATE cxx_std_17)

add_executable(2_23_variadic_templates src/2_23_variadic_templates.cc)
# needs cxx_std_17 because of fold expressions
target_compile_features(2_23_variadic_templates
                        PRIVATE
                        cxx_variadic_templates
                        cxx_std_17)

add_executable(2_25_return_type_deduction src/2_25_return_type_deduction.cc)
target_compile_features(2_25_return_type_deduction PRIVATE
                        cxx_return_type_deduction)

add_executable(2_26_structured_bindings src/2_26_structured_bindings.cc)
target_compile_features(2_26_structured_bindings PRIVATE cxx_std_17)

add_executable(2_2_unified_initialisation src/2_2_unified_initialisation.cc)
target_compile_features(2_2_unified_initialisation
                        PRIVATE
                        cxx_uniform_initialization
                        cxx_aggregate_default_initializers)

add_executable(2_27_selection_statements_with_initializers
               src/2_27_selection_statements_with_initializers.cc)
target_compile_features(2_27_selection_statements_with_initializers PRIVATE
                        cxx_std_17)

add_executable(2_28_standard_attributes src/2_28_standard_attributes.cc)
target_compile_features(2_28_standard_attributes PRIVATE cxx_attributes)
target_compile_options(2_28_standard_attributes
                       PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>)

add_executable(2_29_hex_float_literals src/2_29_hex_float_literals.cc)
target_compile_features(2_29_hex_float_literals
                        PRIVATE
                        cxx_raw_string_literals
                        cxx_digit_separators)

add_executable(2_32_has_include src/2_32_has_include.cc)
target_compile_features(2_32_has_include PRIVATE cxx_std_17)

add_executable(2_32_1_guaranteed_copy_elision
               src/2_32_1_guaranteed_copy_elision.cc)
target_compile_features(2_32_1_guaranteed_copy_elision PRIVATE cxx_std_17)

add_executable(2_32_1_variable_templates src/2_32_1_variable_templates.cc)
target_compile_features(2_32_1_variable_templates PRIVATE
                        cxx_variable_templates)

add_executable(2_3_2_decltype src/2_3_2_decltype.cc)
target_compile_features(2_3_2_decltype PRIVATE cxx_decltype)

add_executable(2_3_type_inference_and_auto src/2_3_type_inference_and_auto.cc)
target_compile_features(2_3_type_inference_and_auto PRIVATE cxx_auto_type)

add_executable(2_5_enums src/2_5_enums.cc)
target_compile_features(2_5_enums PRIVATE cxx_strong_enums)

add_executable(2_6_class_inheritance_keywords
               src/2_6_class_inheritance_keywords.cc)
target_compile_features(2_6_class_inheritance_keywords
                        PRIVATE
                        cxx_final
                        cxx_override)

add_executable(2_6_class_keywords src/2_6_class_keywords.cc)
target_compile_features(2_6_class_keywords
                        PRIVATE
                        cxx_defaulted_functions
                        cxx_deleted_functions)

add_executable(2_9_noexcept src/2_9_noexcept.cc)
target_compile_features(2_9_noexcept PRIVATE cxx_noexcept)

add_executable(2_8_static_asserts src/2_8_static_asserts.cc)
target_compile_features(2_8_static_asserts PRIVATE cxx_static_assert)

add_executable(2_11_nullptr src/2_11_nullptr.cc)
target_compile_features(2_11_nullptr PRIVATE cxx_nullptr)

add_executable(2_12_right_angle_brackets src/2_12_right_angle_brackets.cc)
target_compile_features(2_12_right_angle_brackets PRIVATE
                        cxx_right_angle_brackets)

if(DEFINED ENABLE_CPP20_FEATURES)
  message(INFO "Building C++20 features (Not supported by all compilers)")
  add_executable(2_10_three_way_comparison src/2_10_three_way_comparison.cc)
  target_compile_options(2_10_three_way_comparison
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_14_ranges src/2_14_ranges.cc)
  target_compile_options(2_14_ranges
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_1_math_includes src/2_1_math_includes.cc)
  target_compile_options(2_1_math_includes
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_20_stdspan src/2_20_stdspan.cc)
  target_compile_options(2_20_stdspan
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_22_coroutine_await src/2_22_coroutine_await.cc)
  target_compile_options(2_22_coroutine_await
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_22_coroutine_return src/2_22_coroutine_return.cc)
  target_compile_options(2_22_coroutine_return
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_22_coroutine_yield src/2_22_coroutine_yield.cc)
  target_compile_options(2_22_coroutine_yield
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_24_concepts src/2_24_concepts.cc)
  target_compile_options(2_24_concepts
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_31_modules src/2_31_modules.cc)
  target_compile_options(2_31_modules
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

  add_executable(2_4_std_format src/2_4_std_format.cc)
  target_compile_options(2_4_std_format
                         PRIVATE $<$<CXX_COMPILER_ID:Clang>: --std=c++2a>)

endif()

# if vi improved is detected add a target for generating html output
find_program(VIM_PATH vim)

if(VIM_PATH)

  message("Vim found in ${VIM_PATH}")

  find_program(PYTHON_EXECUTABLE python3)

  # if Python is available the .cc files will be split into chunks for each
  # example in the print version of the booklet. The newly generated files will
  # be appended to the source list to generate the build_html targets once
  # caveat is that if new examples are added/configured in existing files cmake
  # needs to be run again
  if(PYTHON_EXECUTABLE)
    message("found Python3; Splitting cc files into individual examples")
    execute_process(COMMAND ${PYTHON_EXECUTABLE}
                            ${CMAKE_CURRENT_LIST_DIR}/separate_into_examples.py
                            -s
                            ${CMAKE_CURRENT_LIST_DIR}/src
                            -t
                            ${PROJECT_BINARY_DIR}/examples)
    execute_process(COMMAND ${PYTHON_EXECUTABLE}
                            ${CMAKE_CURRENT_LIST_DIR}/highlight_files.py
                            -s
                            ${PROJECT_BINARY_DIR}/examples
                            -t
                            ${PROJECT_BINARY_DIR}/html)

  else()
    message(
      WARNING "Python3 not found, will not build target to separate examples")
  endif()

else()
  message(WARNING "Vim not found, will not add target to build html output")
endif()
