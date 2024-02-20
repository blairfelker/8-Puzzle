set(CMAKE_COMPILER g++)
cmake_minimum_required(VERSION 3.27.4)
project(8-PuzzleC++)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILE main.cpp Puzzle.cpp Search.cpp aStarNode.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})