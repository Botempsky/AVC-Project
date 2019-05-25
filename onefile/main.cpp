#include <iostream>
#include <math.h>
#include <sys/time.h> 
#include "E101.h"
using namespace std;

const static int IMG_WIDTH = 320;
const static int IMG_HEIGHT = 240;
int debug = 0; // condition for enabling debugging print statements

class camera{
	private:
	int whiteness[IMG_WIDTH]; // stores whiteness of each pixel 
	int index[IMG_WIDTH]; // a multiplication matrix of shifted array index values
	const double div = 3243600; // maximum possible value of index[] * whiteness[]
	public:
	
	// returns error value from -1 to 1 
	double getError(){
		double error = 0;
		// iterate horizontally over all the pixels along the middle of the screen 
		for(int i = 0; i < IMG_WIDTH; i++){
			whiteness[i] = get_pixel(IMG_HEIGHT/2, i, 3); // grab whiteness for each pixel and store in array
			// these conditionals are for setting up the index[] array:
			// we want an array with two zeroes in the middle and 159 on either side 
			if(i < IMG_WIDTH/2){
				index[i] = i - (IMG_WIDTH/2)+1;
			}
			else{
				index[i] = i - (IMG_WIDTH/2);
			}
			// add product to error value
			error += (index[i]*whiteness[i]);
			if(debug){
				cout << whiteness[i] << endl;
				cout << error << endl;
			}
		}
		return error/div; // we divide by the maximum possible result to get error between 1 and -1
	}
	
	// checks to see if the line is present
	bool lineCheck(){
		int blackCount = 0;
		for(int i = 0; i < IMG_WIDTH; i++){
			// if the pixel def aint white - increment the counter
			if(get_pixel(IMG_HEIGHT/2, i , 3) < 100){
				blackCount++;
			}
				
		}
		// these are experimentally determined values here...
		if(blackCount > 40 && blackCount < 70){
			return true;
		}
		return false;
	}
		
};



double getTime(){
	struct timespec ts_start;
	struct timespec ts_end;
	clock_gettime(CLOCK_MONOTONIC, &ts_start);
	for(int i = 0; i < 560; i++){
		//code_to_time();
		double x = sin(i);
	}
	clock_gettime(CLOCK_MONOTONIC, &ts_end);
	
	long elapsed = (ts_end.tv_sec-ts_start.tv_sec)*1000000000 + ts_end.tv_nsec-ts_start.tv_nsec;
	return 1.0;
}




int main(){
	// initial setup
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;
	open_screen_stream();

	int count = 0;
	camera cam;
	while(count < 100){
		take_picture();
		update_screen();
		//cout << cam.lineCheck() << endl;
		cout << cam.getError() << endl;
		count++;
		sleep1(1000);
	}
	
	
}
