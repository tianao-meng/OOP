cmake_minimum_required(VERSION 3.15)
project(q2)

set(CMAKE_CXX_STANDARD 11)

add_executable(q2 main.cc target.cc target.h makefile.cc makefile.h)