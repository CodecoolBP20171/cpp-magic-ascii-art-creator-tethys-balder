#include <cmath>
#include "PictConverter.h"

PictConverter::PictConverter(arguments args){
    commandArgs = args;
}

int PictConverter::convertGrey(int red, int green, int blue) {
    return floor(0.3 * red + 0.59 * green + 0.11 * blue);
}