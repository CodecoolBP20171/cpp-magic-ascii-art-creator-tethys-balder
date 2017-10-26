#ifndef ASCII_ART_CREATOR_BMPCONV_H
#define ASCII_ART_CREATOR_BMPCONV_H

#include "PictConverter.h"

class BMPConv : PictConverter {

public:
    explicit BMPConv(arguments myArgs) : PictConverter(myArgs){}
    ~BMPConv() = default;

    virtual PictureContainer loadPicture() override;
};


#endif //ASCII_ART_CREATOR_BMPCONV_H
