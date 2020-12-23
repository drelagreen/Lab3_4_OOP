cmake_minimum_required(VERSION 3.16)
project(clion)

set(CMAKE_CXX_STANDARD 20)

add_executable(clion lab4.cpp Elections.cpp Elections.h ElectionsRepo.cpp ElectionsRepo.h Interactor.cpp Interactor.h)