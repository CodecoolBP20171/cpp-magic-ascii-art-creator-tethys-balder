#ifndef ASCII_ART_CREATOR_PNGCONV_H
#define ASCII_ART_CREATOR_PNGCONV_H

#include "ArgumentumParser.h"
#include "PictureContainer.h"
#include "libs/lodepng/lodepng.h"

class PNGConv {
public:
    PNGConv( arguments args );
    ~PNGConv() = default;

    PictureContainer loadPicture();

private:
    int convertGrey(int red, int green, int blue);

    arguments commandArgs;
};


#endif //ASCII_ART_CREATOR_PNGCONV_H
