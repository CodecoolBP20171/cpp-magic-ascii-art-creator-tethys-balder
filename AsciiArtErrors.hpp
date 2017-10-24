#ifndef ASCII_ART_ERRORS_H
#define ASCII_ART_ERRORS_H

#include <exception>

class TooFewArguments : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Too few arguments!";
    }
};

class BadArgumentsList : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Bad arguments list!";
    }
};

class NotValidFileType : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Not supported file type!";
    }
};

#endif //ASCII_ART_ERRORS_H