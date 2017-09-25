cmake_minimum_required(VERSION 3.6)
project(LB2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Goods.cpp Goods.h helpFunctions.cpp helpFunctions.h clases.cpp clases.h)
add_executable(LB2 ${SOURCE_FILES})