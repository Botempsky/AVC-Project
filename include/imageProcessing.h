#pragma once
#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

class error{
private:
    const static int IMG_WIDTH = 320;
    const static int IMG_HEIGHT = 240;
    
public:
    inline double getError();
    inline double getThresh();
};
#endif



