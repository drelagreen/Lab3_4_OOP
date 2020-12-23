cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled Shape.cpp lab3.cpp ShapeFactory.cpp Square.cpp Rectangle.cpp Interactor.cpp Point.h Shape.h Square.h Rectangle.h ShapeFactory.h Triangle.cpp Triangle.h Exception.h ShapeUtil.cpp ShapeUtil.h)