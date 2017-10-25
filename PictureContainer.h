#ifndef ASCII_ART_CREATOR_PICTURECONTAINER_H
#define ASCII_ART_CREATOR_PICTURECONTAINER_H

#include <cstddef>
#include <vector>

class PictureContainer {

public:
    PictureContainer() = default;
    ~PictureContainer() = default;

    void setHeight(size_t);
    size_t getHeight();

    void setWidth(size_t);
    size_t getWidth();

    void setPixel(size_t, size_t, char);
    char getPixel (size_t, size_t);

private:
    size_t height;
    size_t width;
    std::vector<std::vector <char> > pixels;
};


#endif //ASCII_ART_CREATOR_PICTURECONTAINER_H
