cmake_minimum_required(VERSION 3.22)
project(MyProject)
set(CMAKE_CXX_STANDARD 17)

add_executable(MyProject
        main.cpp
        headers/defines.h
        headers/operators.h
)
