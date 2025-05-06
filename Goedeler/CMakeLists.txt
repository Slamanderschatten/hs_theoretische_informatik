cmake_minimum_required(VERSION 3.25)
project(Goedeler)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")  # Wechsle von `.dll` auf `.a` (statisch)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

# Boost
set(BOOST_ROOT "C:/ProgramData/Boost/boost_1_85_0")
find_package(Boost 1.57.0)
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()
include_directories(${Boost_INCLUDE_DIRS})



set(CMAKE_CXX_STANDARD 17)

add_executable(Goedeler main.cpp)
