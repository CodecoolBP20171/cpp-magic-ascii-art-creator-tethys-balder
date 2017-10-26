#include <iostream>
#include <vector>

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
    catch (TooFewArguments & e) { std::cout << e.what(); }
    catch (BadArgumentsList & e) { std::cout << e.what(); }
    catch (NotValidFileType & e) { std::cout << e.what(); }

    if (cmdArgs.fileType == BitMap) {
        BMPConv BMP_Converter(cmdArgs);
        PictureContainer image = BMP_Converter.loadPicture();
        std::cout << image.getACIIString();
    } else if (cmdArgs.fileType == PNG) {
        PNGConv newPNGPicture(cmdArgs);
        PictureContainer image = newPNGPicture.loadPicture();
        std::cout << image.getACIIString();
    } else if (cmdArgs.fileType == JPEG) {
        JPGConv newJPGPicture(cmdArgs);
        PictureContainer image = newJPGPicture.loadPicture();
        std::cout << image.getACIIString();
    } else {
        std::cout << "Unknown file type";
    }

    return 0;
}
