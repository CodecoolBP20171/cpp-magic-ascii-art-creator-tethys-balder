#include <iostream>
#include "libs/EasyBMP/EasyBMP.h"

int main( int argc, char* argv[]) {
    if( argc != 2 ) {
        std::cout << "Usage: ColorBMPtoGrayscale <input_filename> <output_filename>"
                  << std::endl << std::endl;
        return 1;
    }
// declare and read the bitmap
    for (int k = 0; k < argc; ++k) {
        std::cout << argv[k] << std::endl;
    }
    BMP Input;
    Input.ReadFromFile( argv[1] );
// convert each pixel to grayscale using RGB->YUV
    for( int j=0 ; j < Input.TellHeight() ; j++)
    {
        for( int i=0 ; i < Input.TellWidth() ; i++)
        {
            int Temp = (int) floor( 0.299*Input(i,j)->Red +
                                    0.587*Input(i,j)->Green +
                                    0.114*Input(i,j)->Blue );
            ebmpBYTE TempBYTE = (ebmpBYTE) Temp;
            Input(i,j)->Red = TempBYTE;
            Input(i,j)->Green = TempBYTE;
            Input(i,j)->Blue = TempBYTE;
        }
    }
// Create a grayscale color table if necessary
    if( Input.TellBitDepth() < 16 )
    { CreateGrayscaleColorTable( Input ); }
// write the output file
//    Input.WriteToFile( argv[2] );
    return 0;
}