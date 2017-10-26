#include "PictureContainer.h"

PictureContainer::PictureContainer(int hght, int wdth) {
    height = hght;
    width = wdth;
    std::vector<int> tempVector;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            tempVector.push_back(0);
        }
        pixels.push_back(tempVector);
        tempVector.clear();
    }
}

int PictureContainer::getHeight() {
    return height;
}

int PictureContainer::getWidth() {
    return width;
}

int PictureContainer::getPixel(int h, int w) {
    return pixels[h][w];
}

void PictureContainer::setPixel(int h, int w, int c) {
    pixels[h][w] = c;
}