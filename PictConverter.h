#ifndef ASCII_ART_CREATOR_PICTCONTAINER_H
#define ASCII_ART_CREATOR_PICTCONTAINER_H

#include "ArgumentumParser.h"
#include "PictureContainer.h"

class PictConverter {

public:
    PictConverter( arguments args );
    ~PictConverter() = default;

    virtual PictureContainer loadPicture() = 0;

protected:
    arguments commandArgs;
    int convertGrey(int red, int green, int blue);
};





#endif //ASCII_ART_CREATOR_PICTCONTAINER_H
