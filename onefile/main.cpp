#include <iostream>
#include <math.h>
#include <sys/time.h> 
#include "E101.h"
using namespace std;

const static int IMG_WIDTH = 320;
const static int IMG_HEIGHT = 240;

class camera{
	private:
	int whiteness[IMG_WIDTH];
	int index[IMG_WIDTH];
	double div = 3243600;
	public:
	
	double getError(){
		double error = 0;
		for(int i = 0; i < IMG_WIDTH; i++){
			whiteness[i] = get_pixel(IMG_HEIGHT/2, i, 3);
			if(i < IMG_WIDTH/2){
				index[i] = i - (IMG_WIDTH/2)+1;
			}
			else{
				index[i] = i - (IMG_WIDTH/2);
			}
			cout << whiteness[i] << endl;
			error += (index[i]*whiteness[i]);
			//cout << error << endl;
		}
		return error/div;
	}
	
	bool lineCheck(){
		int blackCount = 0;
		for(int i = 0; i < IMG_WIDTH; i++){
			if(get_pixel(IMG_HEIGHT/2, i , 3) < 100){
				blackCount++;
			}
				
		}
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
		cout << cam.lineCheck() << endl;
		cout << cam.getError() << endl;
		count++;
		sleep1(1000);
	}
	
	
}
