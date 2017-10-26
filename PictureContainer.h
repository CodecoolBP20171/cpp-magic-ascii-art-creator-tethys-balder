#ifndef ASCII_ART_CREATOR_PICTURECONTAINER_H
#define ASCII_ART_CREATOR_PICTURECONTAINER_H

#include <cstddef>
#include <vector>
#include <iostream>

class PictureContainer {

public:
    PictureContainer(int, int);
    ~PictureContainer() = default;

    int getHeight();
    int getWidth();

    void setPixel(int, int, int);
    int getPixel (int, int);
  
    std::string getACIIString();


private:
    int height;
    int width;
    std::vector<std::vector<int>> pixels;
};


#endif //ASCII_ART_CREATOR_PICTURECONTAINER_H
