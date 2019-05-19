/** 
 * This is the code for calculating the proportional error.
 * Im 90% sure itś working correctly but it definitely needs 
 * some more testing. The threshold needs to be determined 
 * and represented as a ratio in order to account for changing light
 * conditions. This would be itś own method when fully integrated with
 * the other code.
 **/
 
#include <iostream>
#include "E101.h"

using namespace std;

	int IMG_WIDTH = 320;
	int IMG_HEIGHT = 240; 
	double threshold = 100; // NEEDS TO BE DETERMINED PROPERLY (been using 100 - 150)
	int pixel [320]; // stores the value pixel brightness along the central line (1 for bright, 0 for dark)
	int index [320]; // stores array indexes shifted by the middle index (shift matrix)

double calculateThreshold() {
	take_picture();
	int minPixel = 255;
	int maxPixel = 0;
	for (int t = 0; t < IMG_WIDTH; t++){
		int pixelValue = get_pixel((IMG_HEIGHT/2), t, 3);
		
		//calculates the maximum pixel value in the row
		if (pixelValue > maxPixel){
			maxPixel = pixelValue;
		}
		
		//calculates the minimum pixel value in the row
		else if (pixelValue < minPixel){
			minPixel = pixelValue;
		}
	}
	
	//calculates the midpoint between the highest and lowest values
	threshold = (minPixel + maxPixel) / 2;
	return threshold;	
	}

int main()
{
	// initialises err (required for operation)
	int err;
	cout<<" Hello"<<endl;
	err = init(0);
	cout<<"After init() error="<<err<<endl;

	int count = 0;
	open_screen_stream();

	while(count < 500){
		
		take_picture();
		update_screen();
		
		int error = 0;
		
		// 
		for(int i = 0; i < IMG_WIDTH; i++){
			//printf("WHITE: %d\n",get_pixel((IMG_HEIGHT/2),i,3));
			if(get_pixel((IMG_HEIGHT/2),i,3) > threshold){
				pixel[i] = 1;
			}
			else{
				pixel[i] = 0;
			}
			index[i] = i - IMG_WIDTH/2;
			error += pixel[i] * index[i];
			//printf("Pixel: %d Shifted Index: %d Index: %d Error: %d\n", pixel[i], index[i], i, pixel[i] * index[i]);
		}
		count ++;
		printf("Frame: %d\n",count);
		printf("Error: %d\n", error);
		
	}
	
}
