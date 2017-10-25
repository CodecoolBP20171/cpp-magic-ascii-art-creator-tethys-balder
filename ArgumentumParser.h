#ifndef ASCII_ART_CREATOR_ARGUMENTUMPARSER_H
#define ASCII_ART_CREATOR_ARGUMENTUMPARSER_H

#include <iostream>

enum fileTypes {BitMap, PNG, JPEG, notGiven};

struct arguments {
    char* fileName;
    fileTypes fileType;
    bool isColor;
};

class ArgumentumParser {
public:
    ArgumentumParser();
    ~ArgumentumParser();

    arguments dealingWithArgs(int, char* []);

private:
    fileTypes getFileType(std::string);
};


#endif //ASCII_ART_CREATOR_ARGUMENTUMPARSER_H
