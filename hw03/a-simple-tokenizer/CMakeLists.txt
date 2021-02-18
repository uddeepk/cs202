cmake_minimum_required(VERSION 3.17)
project(a_simple_tokenizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(a_simple_tokenizer main.cpp TokenAndPosition.cpp TokenAndPosition.hpp)