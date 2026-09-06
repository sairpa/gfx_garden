cmake_minimum_required(VERSION 3.22)
project(vanguard_math LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(vanguard_math INTERFACE)

target_include_directories(vanguard_math INTERFACE include)

add_executable(math_test test/test.cpp)

target_link_libraries(math_test PRIVATE vanguard_math)

set_target_properties(math_test PROPERTIES DEBUG_POSTFIX "_debug")