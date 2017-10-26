#include <iostream>
#include <vector>

#include "libs/lodepng/lodepng.h"
#include "ArgumentumParser.h"
#include "AsciiArtErrors.hpp"
#include "BMPConv.h"

void printResult( std::vector<std::vector<int>> list ) {

    long height = list.size();
    long width = list[0].size();

    for (int k = 0; k < height; ++k) {
        for (int i = 0; i < width; ++i) {
            int valueOfCharacter = list[k][i];

            if      (valueOfCharacter > 226) std::cout << "@";
            else if (valueOfCharacter > 198) std::cout << "#";
            else if (valueOfCharacter > 169) std::cout << "8";
            else if (valueOfCharacter > 141) std::cout << "&";
            else if (valueOfCharacter > 113) std::cout << "o";
            else if (valueOfCharacter > 84)  std::cout << ":";
            else if (valueOfCharacter > 55)  std::cout << "*";
            else if (valueOfCharacter > 27)  std::cout << ".";
            else                             std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void decodeOneStep(const char* filename)
{
    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    //decode
    unsigned error = lodepng::decode(image, width, height, filename);

    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}


int main( int argc, char* argv[] ) {
  
    ArgumentumParser ap;
    arguments cmdArgs;
    try {
        cmdArgs = ap.dealingWithArgs(argc, argv);
    }
    catch (TooFewArguments & e) {}
    catch (BadArgumentsList & e) {}
    catch (NotValidFileType & e) {}

    BMPConv BMP_Converter(cmdArgs);
    PictureContainer picture = BMP_Converter.loadPicture();


    //png
    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;
    //decode
    unsigned error = lodepng::decode(image, width, height, "test1.png");
    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    std::cout << "height: " << height << std::endl;
    std::cout << "width: " << width << std::endl;
    std::cout << image.size();


    return 0;
}
