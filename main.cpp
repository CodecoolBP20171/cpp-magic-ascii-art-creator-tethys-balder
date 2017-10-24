#include <iostream>
#include <sstream>
#include "libs/EasyBMP/EasyBMP.h"
#include "AsciiArtErrors.hpp"
enum fileTypes {BMP, PNG, JPEG, notGiven};

struct arguments{
    std::string fileName;
    fileTypes fileType;
    bool isColor;

};

fileTypes getFileType(std::string type) {
/*    const std::string JPEG_LIST[] = {"jpg", "jpeg"};
    const std::string BMP_LIST[] = {"bmp", "bitmap"};
    const std::string PNG_LIST[] = {"png"};*/

    std::stringstream ss;
    for (char c : type) {
        ss << static_cast <char> ( tolower(c)) ;
    }
    type = ss.str();

    if (type == "bmp" || type == "bitmap") return BMP;
    if (type == "png") return PNG;
    if (type == "jpg" || type == "jpeg") return JPEG;
    throw NotValidFileType();
}

arguments dealingWithArgs(int argc, char* argv[]){
    if (argc < 2) {
        throw TooFewArguments();
    }

    arguments result;
    result.fileName = "";
    result.fileType = notGiven;
    result.isColor = false;

    int index = 1;
    do {
        std::string part = argv[index];
        if (part == "-f") {
            if (index+1 == argc) throw TooFewArguments();
            if (result.fileName == "") {
                result.fileName = argv[index + 1];
                index += 2;
            } else {
                throw BadArgumentsList();
            }
        } else if (part == "-t") {
            if (index+1 == argc) throw TooFewArguments();
            if (result.fileType == notGiven) {
                result.fileType = getFileType(argv[index + 1]);
                index += 2;
            } else {
                throw BadArgumentsList();
            }
        } else if (part == "-color") {
            result.isColor = true;
            ++index;
        } else if (result.fileName == "") {
            result.fileName = argv[index];
            ++index;
        } else throw BadArgumentsList();

    } while( index < argc);

    return result;
}

int main( int argc, char* argv[]) {
    arguments pic = dealingWithArgs(argc, argv);
    std::cout << "File Name: " << pic.fileName << std::endl;
    std::cout << "File type: " << pic.fileType << std::endl;
    std::cout << "Color: " << pic.isColor << std::endl;
    return 0;
}