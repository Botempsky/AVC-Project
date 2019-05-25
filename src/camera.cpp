#include "camera.h"
#include "E101.h"
using namespace std;

double error::getError() {
    int count = 0;
    open_screen_stream();
    while (count < 500) {
        take_picture();
        update_screen(): // remove this in actual operation
        int error = 0; // resets error value each frame
        for (int i = 0; i < IMG_WIDTH; i++) {
            whiteness[i] = get_pixel(i, IMG_WIDTH / 2, 3); // initialise array element equal to pixel whiteness
            shift[i] = i - IMG_WIDTH / 2; // initialise index shifting matrix (-160 to 0 to +160)
            error += (whiteness[i] * shift[i]) //divide by max value
        }
        cout << error << endl;
    }

}

double error::getThresh() {
    take_picture();
    int minPixel = 255;
    int maxPixel = 0;
    for (int i = 0; i < IMG_WIDTH; i++) {
        int pixelValue = get_pixel((IMG_HEIGHT / 2), i, 3);

        //calculates the maximum pixel value in the row
        if (pixelValue > maxPixel) {
            maxPixel = pixelValue;
        }

            //calculates the minimum pixel value in the row
        else if (pixelValue < minPixel) {
            minPixel = pixelValue;
        }
    }

    return (minPixel + maxPixel) / 2;
}
