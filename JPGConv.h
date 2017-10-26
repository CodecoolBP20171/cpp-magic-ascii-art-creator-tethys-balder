#ifndef ASCII_ART_CREATOR_JPGCONV_H
#define ASCII_ART_CREATOR_JPGCONV_H

#include "PictConverter.h"

class JPGConv : PictConverter{
public:
    explicit JPGConv( arguments args ) : PictConverter(args) {};
    ~JPGConv() = default;

    virtual PictureContainer loadPicture() override;

};


#endif //ASCII_ART_CREATOR_JPGCONV_H
