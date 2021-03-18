cmake_minimum_required(VERSION 3.15)
project(q4)

set(CMAKE_CXX_STANDARD 11)

add_executable(q4 main.cpp echo.h echo.cpp textprocess.h textprocess.cpp dropfirst.h dropfirst.cpp doublewords.h doublewords.cpp allcaps.h allcaps.cpp count.h count.cpp decorator.cpp decorator.h)