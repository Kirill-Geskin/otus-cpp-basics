cmake_minimum_required(VERSION 3.5)

project(guess_the_number CXX)

add_executable(Guess_the_number "main.cpp" "func.cpp")

target_compile_features(Guess_the_number PUBLIC cxx_std_17)