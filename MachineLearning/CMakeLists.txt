cmake_minimum_required(VERSION 3.10)
project(MachineLearning)

set(CMAKE_CXX_STANDARD 11)

add_executable(MachineLearning main.cpp neuralNetwork.h artificialNeuron.h)