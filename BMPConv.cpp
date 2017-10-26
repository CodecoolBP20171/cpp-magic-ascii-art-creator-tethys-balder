#include "BMPConv.h"
#include "libs/EasyBMP/EasyBMP.h"

BMPConv::BMPConv(arguments myArgs) {
    commandArgs = myArgs;
}

PictureContainer BMPConv::loadPicture() {
    BMP Input;
    Input.ReadFromFile(commandArgs.fileName );

    PictureContainer picture(Input.TellHeight(), Input.TellWidth());

    for ( int i = 0; i < picture.getHeight(); ++i ) {
        for (int j = 0; j < picture.getWidth(); ++j) {
            picture.setPixel(i,j,(int)Input(j,i)->Red);
        }
    }
    return picture;
}