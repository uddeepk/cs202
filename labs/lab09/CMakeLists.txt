cmake_minimum_required(VERSION 3.17)
project(lab09)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab09 main.cpp Rational.cpp Rational.hpp tests.cpp Complex.cpp Complex.hpp)