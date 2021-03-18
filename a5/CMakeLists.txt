cmake_minimum_required(VERSION 3.15)
project(a5)

set(CMAKE_CXX_STANDARD 11)

add_executable(a5 main.cpp player.cpp player.h board.h board.cpp square.h square.cpp square_ownable.h square_ownable.cpp square_unownable.h square_unownable.cpp academic.h academic.cpp Chance_and_Community_chest.h Chance_and_Community_chest.cpp monopoly.h monopoly.cpp building_type.h)