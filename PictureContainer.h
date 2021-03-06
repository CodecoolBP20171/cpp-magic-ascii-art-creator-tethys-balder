#ifndef ASCII_ART_CREATOR_PICTURECONTAINER_H
#define ASCII_ART_CREATOR_PICTURECONTAINER_H

#include <cstddef>
#include <vector>
#include <iostream>

class PictureContainer {

public:
    PictureContainer(int height, int width);
    ~PictureContainer() = default;

    int getHeight();
    int getWidth();

    void setPixel(int height, int width, int value);
    int getPixel (int height, int width);

    void changePictureSize(int divisor);
  
    std::string getACIIString();


private:
    int height;
    int width;
    std::vector<std::vector<int>> pixels;
    std::vector<std::vector<int>> newPicture;
};


#endif //ASCII_ART_CREATOR_PICTURECONTAINER_H
