cmake_minimum_required(VERSION 3.8)
project(Ascii_art_creator)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp AsciiArtErrors.hpp
        libs/EasyBMP/EasyBMP.cpp libs/EasyBMP/EasyBMP.h
        libs/lodepng/lodepng.h libs/lodepng/lodepng.cpp
        ArgumentumParser.cpp ArgumentumParser.h PictureContainer.cpp PictureContainer.h PNGConv.cpp PNGConv.h)

add_executable(Ascii_art_creator ${SOURCE_FILES})