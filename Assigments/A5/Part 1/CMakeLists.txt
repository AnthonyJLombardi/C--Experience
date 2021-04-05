cmake_minimum_required(VERSION 3.14)
project(SortFile)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortFile SortFile.cpp SortFile.h Buffer.h Buffer.cpp)