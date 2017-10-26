#include <iostream>
#include <vector>

#include "ArgumentumParser.h"
#include "AsciiArtErrors.hpp"
#include "PictureContainer.h"

#include "PNGConv.h"
#include "BMPConv.h"




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

    PNGConv newPNGPicture(cmdArgs);
    PictureContainer image = newPNGPicture.loadPicture();
    std::cout << image.getACIIString();

    return 0;
}
