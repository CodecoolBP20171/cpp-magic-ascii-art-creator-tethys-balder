#include "JPGConv.h"
#include "libs/nanoJPEG/jpeg_decoder.h"

PictureContainer JPGConv::loadPicture() {
    size_t size;
    unsigned char *buf;
    FILE *f;
    f = fopen(commandArgs.fileName, "rb");

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    buf = (unsigned char*)malloc(size);
    fseek(f, 0, SEEK_SET);
    size_t read = fread(buf, 1, size, f);
    fclose(f);

    Jpeg::Decoder decoder(buf, size);
    int height = decoder.GetHeight();
    int width = decoder.GetWidth();
    PictureContainer GrayscalePicture(height, width);

    int grey;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int pix_index = 3*width*i+3*j;
            if (commandArgs.isColor) {
                grey = convertGrey(decoder.GetImage()[pix_index], decoder.GetImage()[pix_index+1], decoder.GetImage()[pix_index+2]);
            } else {
                grey = decoder.GetImage()[pix_index];
            }
            GrayscalePicture.setPixel(i, j, grey);
        }
    }
    return GrayscalePicture;

}