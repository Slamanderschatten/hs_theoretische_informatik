cmake_minimum_required(VERSION 3.25)
project(Turingmaschine)

set(CMAKE_CXX_STANDARD 17)
set(MANIFEST_FILE "${CMAKE_SOURCE_DIR}/Turingmaschine.manifest")



add_executable(Turingmaschine main.cpp)
set_target_properties(Turingmaschine PROPERTIES
        WIN32_EXECUTABLE YES
        MACOSX_BUNDLE YES
        RESOURCE ${MANIFEST_FILE}
        )
