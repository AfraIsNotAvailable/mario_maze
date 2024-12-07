cmake_minimum_required(VERSION 3.30)
project(mario_maze)

set(CMAKE_CXX_STANDARD 20)

add_executable(mario_maze main.cpp
        backtracking.cpp
        backtracking.h
        utils.cpp
        utils.h
        menu.cpp
        menu.h)
