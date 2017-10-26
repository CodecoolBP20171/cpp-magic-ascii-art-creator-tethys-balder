#ifndef ASCII_ART_CREATOR_JPGCONV_H
#define ASCII_ART_CREATOR_JPGCONV_H


#include "ArgumentumParser.h";
#include "PictureContainer.h";"

class JPGConv {
public:
    JPGConv( arguments args );
    ~JPGConv() = default;

    PictureContainer loadPicture();

private:
    arguments commandArgs;
};


#endif //ASCII_ART_CREATOR_JPGCONV_H
