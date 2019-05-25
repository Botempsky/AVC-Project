#include "camera.h"
#include "E101.h"
double error::getError(){
    
}
double error::getThresh(){
    take_picture();
    int minPixel = 255;
    int maxPixel = 0;
    for (int i = 0; i < IMG_WIDTH; i++){
        int pixelValue = get_pixel((IMG_HEIGHT/2), i, 3);
        
        //calculates the maximum pixel value in the row
        if (pixelValue > maxPixel){
            maxPixel = pixelValue;
        }
        
        //calculates the minimum pixel value in the row
        else if (pixelValue < minPixel){
            minPixel = pixelValue;
        }
    }
    
    return (minPixel + maxPixel) / 2;
}
