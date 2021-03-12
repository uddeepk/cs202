cmake_minimum_required(VERSION 3.17)
project(test_arena)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_arena main.cpp CApp.cpp CApp.h)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(test_arena ${SDL2_LIBRARIES})

set(OpenGlLinkers -lglut -lGLU -lGL) # setting all the Glut libraries as one variable.
#set(OpenGlLinkers -lGL) # setting all the Glut libraries as one variable.

set(GLEW_STATIC -DGLEW_STATIC)
################################################


target_link_libraries(test_arena ${OpenGlLinkers})