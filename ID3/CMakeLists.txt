cmake_minimum_required(VERSION 3.10)
project(ID3)

set(CMAKE_CXX_STANDARD 11)

add_executable(ID3 main.cpp ID3.cpp ID3.h loadData.h)