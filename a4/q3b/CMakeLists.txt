cmake_minimum_required(VERSION 3.15)
project(q3b)

set(CMAKE_CXX_STANDARD 14)

add_executable(q3b main.cpp cell.h cell.cpp grid.cpp grid.h info.h observer.h subject.cpp subject.h subscriptions.h textdisplay.cpp textdisplay.h window.cpp window.h GraphicsDisplay.h GraphicsDisplay.cpp)