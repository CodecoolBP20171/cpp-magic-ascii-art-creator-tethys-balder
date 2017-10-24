#include <iostream>
#include "libs/EasyBMP/EasyBMP.h"


int main( int argc, char* argv[]) {
    if( argc != 2 ) {
        std::cout << "Usage: ColorBMPtoGrayscale <input_filename> <output_filename>"
                  << std::endl << std::endl;
        return 1;
    }
// declare and read the bitmap
    BMP Input;
    Input.ReadFromFile( argv[1] );
// convert each pixel to grayscale using RGB->YUV
    int height = Input.TellHeight();
    int width = Input.TellWidth();
    int GrayscaleValueList[height][width];
    for( int j=0 ; j < height ; ++j)
    {
        for( int i=0 ; i < width ; ++i)
        {
            int Temp = (int) floor( 0.299*Input(i,j)->Red +
                                    0.587*Input(i,j)->Green +
                                    0.114*Input(i,j)->Blue );
            ebmpBYTE TempBYTE = (ebmpBYTE) Temp;
            Input(i,j)->Red = TempBYTE;
            Input(i,j)->Green = TempBYTE;
            Input(i,j)->Blue = TempBYTE;
            GrayscaleValueList[i][j] = Temp;
        }
    }
// Create a grayscale color table if necessary
    if( Input.TellBitDepth() < 16 )
    { CreateGrayscaleColorTable( Input ); }
// write the output file
//    Input.WriteToFile( argv[2] );

    for (int k = 0; k < height; ++k) {
        for (int i = 0; i < width; ++i) {
            int valueOfCharacter = GrayscaleValueList[i][k];
            if      (valueOfCharacter > 227) std::cout << "@";
            else if (valueOfCharacter > 199) std::cout << "#";
            else if (valueOfCharacter > 171) std::cout << "8";
            else if (valueOfCharacter > 143) std::cout << "&";
            else if (valueOfCharacter > 115) std::cout << "o";
            else if (valueOfCharacter > 87)  std::cout << ":";
            else if (valueOfCharacter > 59)  std::cout << "*";
            else if (valueOfCharacter > 31)  std::cout << ".";
            else                      std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
 *
BLACK = "@";
CHARCOAL = "#";
DARKGRAY = "8";
MEDIUMGRAY = "&";
MEDIUM = "o";
GRAY = ":";
SLATEGRAY = "*";
LIGHTGRAY = ".";
WHITE = " ";
 */