#include <cmath>
#include "PNGConv.h"


PNGConv::PNGConv( arguments args ) {
    this->commandArgs = args;
}

int PNGConv::convertGrey(int red, int green, int blue) {
    return floor(0.3 * red + 0.59 * green + 0.11 * blue);
}

PictureContainer PNGConv::loadPicture() {

    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    unsigned error = lodepng::decode(image, width, height, commandArgs.fileName);
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;


    PictureContainer GrayscalePicture(height, width);

    int grey;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            if (commandArgs.isColor) {
                grey = convertGrey(image[4*width*i+4*j], image[4*width*i+4*j +1], image[4*width*i+4*j +2]);
            } else {
                grey = image[4*width*i+4*j];
            }

            GrayscalePicture.setPixel(i, j, grey);
        }
    }
    return GrayscalePicture;
}
