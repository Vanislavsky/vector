cmake_minimum_required(VERSION 3.17)
project(vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(/Users/sergejvanislavskij/CLionProjects/vector/vector.h)
add_executable(vector main.cpp vector.cpp vector.h)