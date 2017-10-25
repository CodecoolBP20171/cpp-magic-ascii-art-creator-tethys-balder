#include "PictureContainer.h"

void PictureContainer::setHeight(size_t hght) {
    height = hght;
}

void PictureContainer::setWidth(size_t wdth) {
    width = wdth;
}

size_t PictureContainer::getHeight() {
    return height;
}

size_t PictureContainer::getWidth() {
    return width;
}

char PictureContainer::getPixel(size_t h, size_t w) {
    return pixels[h][w];
}

void PictureContainer::setPixel(size_t h, size_t w, char c) {
    pixels[h][w] = c;
}