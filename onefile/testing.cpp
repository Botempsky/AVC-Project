#include <iostream>
#include <sys/time.h> 
#include "E101.h"
using namespace std;

const static int IMG_WIDTH = 320;
const static int IMG_HEIGHT = 240;

int main(){
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;
	
	/**
	open_screen_stream();
	int count = 0;
	int white = 0;
	int linecheck = 0;
	while(count < 1){
		take_picture();
		update_screen();
		for(int i = 0; i < IMG_WIDTH; i++){
			white = get_pixel(IMG_HEIGHT/2, i , 3);
			//printf("I: %d /t White: %d\n",i,white);
			if(white < 100){
				linecheck++;
			}
		}
		cout << linecheck << endl;
		
		
		count++;
	}
	**/
	
	for(int i = 0; i < 20; i++){
		struct timespec start;
		clock_gettime(CLOCK_MONOTONIC, &start);
		double time = start.tv_sec * 1000000000 + start.tv_nsec;
		cout << time << endl;
		
	}
}
