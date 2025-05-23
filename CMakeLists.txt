cmake_minimum_required(VERSION 3.15)

project(TicTacToe)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(game
    src/board.cc
    src/main.cc
    src/game.cc
)