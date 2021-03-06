#include <sstream>
#include "ArgumentumParser.h"
#include "AsciiArtErrors.hpp"

ArgumentumParser::ArgumentumParser() {};
ArgumentumParser::~ArgumentumParser() = default;

arguments ArgumentumParser::dealingWithArgs(int argc, char* argv[]) {
    if (argc < 2) {
        throw TooFewArguments();
    }

    arguments result;
    result.fileName = "";
    result.fileType = notGiven;
    result.isColor = false;

//    for (int i = 1; i < argc; ++i) {
//        std::string part = argv[i];
//        if (part == "-color") result.isColor = true;
//        else result.fileName = argv[i];
//    }

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

    if (result.fileType == notGiven) {
        std::string fileName = result.fileName;
        result.fileType = getFileType(fileName.substr(fileName.size() - 3, fileName.size()));
    }

    return result;
}

fileTypes ArgumentumParser::getFileType(std::string type) {
    std::stringstream ss;
    for (char c : type) {
        ss << static_cast <char> ( tolower(c)) ;
    }
    type = ss.str();

    if (type == "bmp") return BitMap;
    if (type == "png") return PNG;
    if (type == "jpg") return JPEG;
    throw NotValidFileType();
}
