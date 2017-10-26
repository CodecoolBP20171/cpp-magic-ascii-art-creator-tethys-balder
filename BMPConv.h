#ifndef ASCII_ART_CREATOR_BMPCONV_H
#define ASCII_ART_CREATOR_BMPCONV_H


#include "ArgumentumParser.h"
#include "PictureContainer.h"

class BMPConv {

public:
    BMPConv(arguments);
    ~BMPConv() = default;

    PictureContainer loadPicture();

private:
    int convertGrey(int red, int green, int blue);

    arguments commandArgs;
};


#endif //ASCII_ART_CREATOR_BMPCONV_H
