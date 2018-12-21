cmake_minimum_required(VERSION 3.9)
project(CPS)

set(CMAKE_CXX_STANDARD 11)

add_library(CPS library.cpp library.h Route.cpp Route.h takeoff_n_land.cpp)