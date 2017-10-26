#include <cmath>
#include "JPGConv.h"
#include "libs/nanoJPEG/jpeg_decoder.h"

JPGConv::JPGConv( arguments args ) {
    this->commandArgs = args;
}

PictureContainer JPGConv::loadPicture() {
    size_t size;
    unsigned char *buf;
    FILE *f;

//    if (args < 2) {
//        printf("Usage: %s <input.jpg> [<output.ppm>]\n", argv[0]);
//        return 2;
//    }
    f = fopen(commandArgs.fileName, "rb");
//    if (!f) {
//        printf("Error opening the input file.\n");
//        return 1;
//    }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    buf = (unsigned char*)malloc(size);
    fseek(f, 0, SEEK_SET);
    size_t read = fread(buf, 1, size, f);
    fclose(f);

    Jpeg::Decoder decoder(buf, size);
//    if (decoder.GetResult() != Jpeg::Decoder::OK)
//    {
//        printf("Error decoding the input file\n");
//        return 1;
//    }

//    f = fopen((argc > 2) ? argv[2] : (decoder.IsColor() ? "jpeg_out.ppm" : "jpeg_out.pgm"), "wb");
//    if (!f) {
//        printf("Error opening the output file.\n");
//        return 1;
//    }
//    fprintf(f, "P%d\n%d %d\n255\n", decoder.IsColor() ? 6 : 5, decoder.GetWidth(), decoder.GetHeight());
//    fwrite(decoder.GetImage(), 1, decoder.GetImageSize(), f);
//    fclose(f);


    int height = decoder.GetHeight();
    int width = decoder.GetWidth();
    PictureContainer GrayscalePicture(height, width);

    for (int i = 0; i < height; ++i) {

        for (int j = 0; j < width; ++j) {

            int RGB[3];

            for (int k = 0; k < 3; ++k) {
                RGB[k] = decoder.GetImage()[3*width*i+3*j+k];
            }
            auto grayScaleValue = (int) floor(0.3 * RGB[0] + 0.59 * RGB[1] + 0.11 * RGB[2]);
            GrayscalePicture.setPixel(i, j, grayScaleValue);
        }
    }
    return GrayscalePicture;

}