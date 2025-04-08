cmake_minimum_required(VERSION 3.25)
project(Turingmaschine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")  # Wechsle von `.dll` auf `.a` (statisch)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")


add_executable(Turingmaschine main.cpp)

