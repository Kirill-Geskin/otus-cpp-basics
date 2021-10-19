cmake_minimum_required(VERSION 3.5)

project(Hello CXX)

add_executable(Hello hello_world.cpp todo_move_me_out.cpp)

target_compile_features(Hello PUBLIC cxx_std_17)