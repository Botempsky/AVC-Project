#pragma once
#ifndef CAMERA_H
#define CAMERA_H

class error{
private:
    const static int IMG_WIDTH = 320;
    const static int IMG_HEIGHT = 240;
    int whiteness [IMG_WIDTH];
    int shift [IMG_WIDTH];
    
public:
    inline double getError();
    inline double getThresh();
};
#endif



