cmake_minimum_required(VERSION 3.8)
project(Ascii_art_creator)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp AsciiArtErrors.hpp
        libs/EasyBMP/EasyBMP.cpp libs/EasyBMP/EasyBMP.h
        libs/lodepng/lodepng.h libs/lodepng/lodepng.cpp
        libs/nanoJPEG/jpeg_decoder.h libs/nanoJPEG/nanojpeg.c
        ArgumentumParser.cpp ArgumentumParser.h PictureContainer.cpp PictureContainer.h
        BMPConv.cpp BMPConv.h PNGConv.cpp PNGConv.h JPGConv.cpp JPGConv.h PictConverter.cpp PictConverter.h)


add_executable(Ascii_art_creator ${SOURCE_FILES})