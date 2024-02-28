cmake_minimum_required(VERSION 3.17)
project(battleship)

set(CMAKE_CXX_STANDARD 17)

add_executable(battleship main.cpp
        Ship.cpp
        Ship.h
        Board.cpp
        Board.h
        User.cpp
        User.h
        Game.cpp
        Game.h
)
