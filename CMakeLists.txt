cmake_minimum_required(VERSION 3.12)
project(ex1_cpp)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS -Wall -Wextra -pthread -g)

add_executable(ex1_cpp tester.cpp Vector3D.cpp Vector3D.h Matrix3D.cpp Matrix3D.h)