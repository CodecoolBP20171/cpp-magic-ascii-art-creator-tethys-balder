#include <iostream>
#include <vector>
#include "libs/EasyBMP/EasyBMP.h"
#include "libs/lodepng/lodepng.h"
#include "ArgumentumParser.h"
#include "AsciiArtErrors.hpp"
#include "PictureContainer.h"
#include "PNGConv.h"


//std::vector<std::vector<int>> convertBmpFile( BMP Input ) {
//
//    std::vector<std::vector<int>> GrayscaleValueList;
//
//    int height = Input.TellHeight();
//    int width = Input.TellWidth();
//
//    for( int j=0 ; j < height ; ++j ) {
//        std::vector<int> column;
//
//        for( int i=0 ; i < width ; ++i ) {
//            int Temp = (int) floor( 0.299*Input(i,j)->Red + 0.587*Input(i,j)->Green + 0.114*Input(i,j)->Blue );
//            ebmpBYTE TempBYTE = ( ebmpBYTE ) Temp;
//            Input(i,j)->Red = TempBYTE;
//            Input(i,j)->Green = TempBYTE;
//            Input(i,j)->Blue = TempBYTE;
//            column.push_back( Temp );
//        }
//        GrayscaleValueList.push_back( column );
//    }
//    return GrayscaleValueList;
//}
//
//void decodeOneStep(const char* filename)
//{
//    std::vector<unsigned char> image; //the raw pixels
//    unsigned width, height;
//
//    //decode
//    unsigned error = lodepng::decode(image, width, height, filename);
//
//    //if there's an error, display it
//    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
//
//    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
//}


int main( int argc, char* argv[] ) {
  
    ArgumentumParser ap;
    arguments pic;
    pic = ap.dealingWithArgs(argc, argv);
//    try {
//    }
//    catch (TooFewArguments & e) {}
//    catch (BadArgumentsList & e) {}
//    catch (NotValidFileType & e) {}

    PNGConv newPNGPicture(pic);
    PictureContainer image = newPNGPicture.loadPicture();
    std::cout << image.getACIIString();


    return 0;
}
