cmake_minimum_required(VERSION 3.16)
project(minesweeper)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "--sysroot ${CMAKE_OSX_SYSROOT} ${CMAKE_CXX_FLAGS}")

add_executable(minesweeper main.cpp Board.cpp Board.h Player.cpp Player.h Button.cpp Button.h)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(minesweeper sfml-system sfml-window sfml-graphics sfml-audio sfml-network)