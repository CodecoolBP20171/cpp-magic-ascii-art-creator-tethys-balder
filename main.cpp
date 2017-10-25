#include <iostream>
#include <vector>
#include "libs/EasyBMP/EasyBMP.h"
#include "ArgumentumParser.h"
#include "AsciiArtErrors.hpp"

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


std::vector<std::vector<int>> convertBmpFile( BMP Input ) {

    std::vector<std::vector<int>> GrayscaleValueList;

    int height = Input.TellHeight();
    int width = Input.TellWidth();

    for( int j=0 ; j < height ; ++j ) {
        std::vector<int> column;

        for( int i=0 ; i < width ; ++i ) {
            int Temp = (int) floor( 0.299*Input(i,j)->Red + 0.587*Input(i,j)->Green + 0.114*Input(i,j)->Blue );
            ebmpBYTE TempBYTE = ( ebmpBYTE ) Temp;
            Input(i,j)->Red = TempBYTE;
            Input(i,j)->Green = TempBYTE;
            Input(i,j)->Blue = TempBYTE;
            column.push_back( Temp );
        }
        GrayscaleValueList.push_back( column );
    }
    return GrayscaleValueList;
}


int main( int argc, char* argv[] ) {
  
    ArgumentumParser ap;
    arguments pic;
    try {
        pic = ap.dealingWithArgs(argc, argv);
    }
    catch (TooFewArguments & e) {}
    catch (BadArgumentsList & e) {}
    catch (NotValidFileType & e) {}



    BMP Input;
    Input.ReadFromFile(pic.fileName );

    std::vector<std::vector<int>> GrayscaleValueList = convertBmpFile( Input );
    printResult( GrayscaleValueList );
  
    return 0;
}
