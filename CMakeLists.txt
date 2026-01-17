cmake_minimum_required(VERSION 4.1)
project(TerminalMenu)

set(CMAKE_CXX_STANDARD 20)

add_executable(TerminalMenu src/main.cpp
        src/terminal.h
        src/menu.h
        src/menu.cpp)
