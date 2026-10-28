
cmake_minimum_required(VERSION 3.16)

project(MatrixCalculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(matrix src/matrix.cpp)
target_include_directories(matrix PUBLIC include)

add_executable(matrix_calculator src/main.cpp)
target_link_libraries(matrix_calculator PRIVATE matrix)

enable_testing()

find_package(GTest REQUIRED)

add_executable(matrix_tests tests/test_matrix.cpp)
target_link_libraries(matrix_tests PRIVATE matrix GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(matrix_tests)
