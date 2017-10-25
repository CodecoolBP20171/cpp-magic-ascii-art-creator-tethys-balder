#ifndef ASCII_ART_CREATOR_ARGUMENTUMPARSER_H
#define ASCII_ART_CREATOR_ARGUMENTUMPARSER_H

#include <iostream>;

enum fileTypes {BMP, PNG, JPEG, notGiven};

struct arguments {
    std::string fileName;
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
