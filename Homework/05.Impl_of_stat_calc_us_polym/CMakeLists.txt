cmake_minimum_required(VERSION 3.5)

project(Statistics)

add_executable(statistics
        src/main.cpp
        src/CMax.cpp
        src/CMean.cpp
        src/CMin.cpp
        src/CPct90.cpp
        src/CPct95.cpp
        src/CStdDev.cpp)