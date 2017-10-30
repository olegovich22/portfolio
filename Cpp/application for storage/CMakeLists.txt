cmake_minimum_required(VERSION 3.6)
project(LW3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp clases.cpp clases.h Goods.cpp Goods.h helpFunctions.h helpFunctions.cpp)
add_executable(LW3 ${SOURCE_FILES})