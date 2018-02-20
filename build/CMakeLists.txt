cmake_minimum_required(VERSION 2.8)

project(LED)

add_executable(led ../ledMatrix.cpp)

install(TARGETS led DESTINATION ../)
