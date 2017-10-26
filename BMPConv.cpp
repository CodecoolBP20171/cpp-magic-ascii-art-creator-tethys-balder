#include "BMPConv.h"
#include "libs/EasyBMP/EasyBMP.h"


PictureContainer BMPConv::loadPicture() {
    BMP Input;
    Input.ReadFromFile(commandArgs.fileName );

    PictureContainer picture(Input.TellHeight(), Input.TellWidth());
    int grey;
    for ( int i = 0; i < picture.getHeight(); ++i ) {
        for (int j = 0; j < picture.getWidth(); ++j) {

            if (commandArgs.isColor) {
                grey = convertGrey((int) Input(j,i)->Red, (int) Input(j,i)->Green, (int) Input(j,i)->Blue );
            } else {
                grey = (int)Input(j,i)->Red;
            }
            picture.setPixel(i,j,grey);
        }
    }
    return picture;
}