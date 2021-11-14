cmake_minimum_required(VERSION 3.5)

project(Guess_the_number CXX)

add_executable(Guess_the_number "Main.cpp" "DeclFunc.h" "Func.cpp")

target_compile_features(Guess_the_number PUBLIC cxx_std_17)