cmake_minimum_required(VERSION 3.17)
project(battleship)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(battleship main.cpp Ship.cpp Board.cpp User.cpp Game.cpp)

target_include_directories(battleship PRIVATE "${CMAKE_SOURCE_DIR}/include")
