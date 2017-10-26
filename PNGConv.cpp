#include <cmath>
#include "PNGConv.h"


PNGConv::PNGConv( arguments args ) {
    this->commandArgs = args;
}

PictureContainer PNGConv::loadPicture() {

    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    unsigned error = lodepng::decode(image, width, height, commandArgs.fileName);
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;


    PictureContainer GrayscalePicture;
    GrayscalePicture.setHeight( height );
    GrayscalePicture.setWidth( width );

    for (int i = 0; i < height; ++i) {

        for (int j = 0; j < width; ++j) {

            int RGBA[4];

            for (int k = 0; k < 4; ++k) {
                RGBA[k] = image[4*width*i+4*j+k];
            }
            auto grayScaleValue = (int) floor(0.3 * RGBA[0] + 0.59 * RGBA[1] + 0.11 * RGBA[2]);
            GrayscalePicture.setPixel(i, j, grayScaleValue);
        }
    }
    return GrayscalePicture;
}
