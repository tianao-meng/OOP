cmake_minimum_required(VERSION 3.15)
project(q3)

set(CMAKE_CXX_STANDARD 14)

add_executable(q3 main.cpp cell.cpp cell.h grid.cpp grid.h subject.h subject.cpp subscriptions.h textdisplay.h textdisplay.cpp window.h window.cpp observer.h info.h)