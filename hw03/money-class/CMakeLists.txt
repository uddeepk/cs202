cmake_minimum_required(VERSION 3.17)
project(money_class)

set(CMAKE_CXX_STANDARD 17)

add_executable(money_class moneytest.cpp Money.cpp Money.hpp catch.hpp)