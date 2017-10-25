#include <iostream>
#include <sstream>
#include "libs/EasyBMP/EasyBMP.h"
#include "ArgumentumParser.h"


int main( int argc, char* argv[]) {

    ArgumentumParser ap;
    
    arguments pic = ap.dealingWithArgs(argc, argv);
    std::cout << "File Name: " << pic.fileName << std::endl;
    std::cout << "File type: " << pic.fileType << std::endl;
    std::cout << "Color: " << pic.isColor << std::endl;
    return 0;
}