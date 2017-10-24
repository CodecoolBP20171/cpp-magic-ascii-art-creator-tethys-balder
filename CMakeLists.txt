cmake_minimum_required(VERSION 3.8)
project(Ascii_art_creator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp libs/EasyBMP/EasyBMP.cpp)
add_executable(Ascii_art_creator ${SOURCE_FILES})