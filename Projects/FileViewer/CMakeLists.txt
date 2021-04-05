cmake_minimum_required(VERSION 3.14)
project(FileViewer)

set(CMAKE_CXX_STANDARD 14)

add_executable(FileViewer test.cpp Buffer.cpp Buffer.h FileViewer.h FileViewer.cpp)