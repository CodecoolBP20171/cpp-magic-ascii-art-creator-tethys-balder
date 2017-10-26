#include <iostream>
#include <vector>

#include "libs/lodepng/lodepng.h"
#include "ArgumentumParser.h"
#include "AsciiArtErrors.hpp"

#include "PictureContainer.h"
#include "PNGConv.h"

#include "BMPConv.h"
#include "JPGConv.h"


int main( int argc, char* argv[] ) {
  
    ArgumentumParser ap;
    arguments cmdArgs;
    try {
        cmdArgs = ap.dealingWithArgs(argc, argv);
    }
    catch (TooFewArguments & e) { std::cout << "asd"; }
    catch (BadArgumentsList & e) { std::cout << "asd"; }
    catch (NotValidFileType & e) { std::cout << "asd"; }

//    BMPConv BMP_Converter(cmdArgs);
//    PictureContainer picture = BMP_Converter.loadPicture();
//    std::cout << picture.getACIIString();

//    PNGConv newPNGPicture(cmdArgs);
//    PictureContainer image = newPNGPicture.loadPicture();
//    std::cout << image.getACIIString();

    JPGConv newJPGPicture(cmdArgs);
    PictureContainer image = newJPGPicture.loadPicture();
    std::cout << image.getACIIString();

    return 0;
}
