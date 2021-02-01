cmake_minimum_required(VERSION 3.17)
project(time_it_ii)

set(CMAKE_CXX_STANDARD 17)

add_executable(time_it_ii main.cpp  ../time-it-i/StopWatch.hpp ../time-it-i/StopWatch.cpp)
