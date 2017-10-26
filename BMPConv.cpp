#include "BMPConv.h"
#include "libs/EasyBMP/EasyBMP.h"

int BMPConv::convertGrey(int red, int green, int blue) {
    return floor(0.3 * red + 0.59 * green + 0.11 * blue);
}

BMPConv::BMPConv(arguments myArgs) {
    commandArgs = myArgs;
}

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