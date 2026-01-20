cmake_minimum_required(VERSION 3.20)
project(binary_search LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library (INTERFACE)
add_library(binary_search INTERFACE)
add_library(binary_search::binary_search ALIAS binary_search)

target_include_directories(binary_search INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if (MSVC)
  target_compile_options(binary_search INTERFACE /W4 /permissive-)
else()
  target_compile_options(binary_search INTERFACE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
enable_testing()

add_executable(binary_search_basic_test tests/test_basic.cpp)
target_link_libraries(binary_search_basic_test PRIVATE binary_search::binary_search)
add_test(NAME binary_search.basic COMMAND binary_search_basic_test)
