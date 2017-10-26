#ifndef ASCII_ART_CREATOR_PNGCONV_H
#define ASCII_ART_CREATOR_PNGCONV_H

#include "libs/lodepng/lodepng.h"
#include "PictConverter.h"

class PNGConv : PictConverter {
public:
    explicit PNGConv( arguments args ) : PictConverter(args) {};
    ~PNGConv() = default;

    virtual PictureContainer loadPicture() override ;
};


#endif //ASCII_ART_CREATOR_PNGCONV_H
