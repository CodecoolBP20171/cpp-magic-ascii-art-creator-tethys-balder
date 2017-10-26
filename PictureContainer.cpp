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

void PictureContainer::setPixel(int h, int w, int i) {
    pixels[h][w] = i;
}

std::string PictureContainer::getACIIString() {
    std::string ASCII;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            int valueOfCharacter = getPixel(i, j);

            if      (valueOfCharacter > 226) ASCII += " ";
            else if (valueOfCharacter > 198) ASCII += ".";
            else if (valueOfCharacter > 170) ASCII += "*";
            else if (valueOfCharacter > 142) ASCII += ":";
            else if (valueOfCharacter > 114) ASCII += "o";
            else if (valueOfCharacter > 86)  ASCII += "&";
            else if (valueOfCharacter > 58)  ASCII += "8";
            else if (valueOfCharacter > 30)  ASCII += "#";
            else                             ASCII += "@";
        }
        ASCII += "\n";
    }

    return ASCII;
}

