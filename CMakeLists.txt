cmake_minimum_required(VERSION 3.10)


project(FASTERMATRIXLIBRARY CXX)


set(SRC 

main.cpp
Matrix.cpp
Matrix.h
NN.cpp
NN.h
Timer.cpp
Timer.h

)

add_executable(FASTERMATRIXLIBRARY ${SRC})