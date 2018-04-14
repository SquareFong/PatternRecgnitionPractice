cmake_minimum_required(VERSION 3.10)
project(NaiveBayes)

set(CMAKE_CXX_STANDARD 11)

add_executable(NaiveBayes main.cpp loadData.h NaiveBayes.cpp NaiveBayes.h)