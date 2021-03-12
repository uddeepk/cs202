cmake_minimum_required(VERSION 3.17)
project(testopengl1_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(testopengl1_1 main.cpp glad.c)

target_link_libraries(testopengl1_1 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl)
#note: changed -lglfw3 to -lglfw