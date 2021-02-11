cmake_minimum_required(VERSION 3.17)
project(cave_spelunking)

set(CMAKE_CXX_STANDARD 17)

add_executable(cave_spelunking main.cpp Cave.cpp Cave.hpp)