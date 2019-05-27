#include <iostream>
#include <cmath>
#include <sys/time.h>
#include "E101.h"
using namespace std;

int debug = 0; // condition for enabling debugging print statements

// opens gate
int openGate(){
	char ipadd[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
	char request[24] = {'P','l','e','a','s','e'};
	char pass[24];
	connect_to_server(ipadd, 1024);
	send_to_server(request);
	receive_from_server(pass);
	send_to_server(pass);
	return 1;
}


// returns current time RESULT IS IN NANOSECONDS 
long getTime(){
	struct timespec start; // we make a timespec that stores the time
	clock_gettime(CLOCK_MONOTONIC, &start); // get current time (arbitrary)
	long time = start.tv_sec + start.tv_nsec; // convert time into a useable number (in nanoseconds)
	return time;
}

class camera{
	private:
	const static int IMG_WIDTH = 320;
	const static int IMG_HEIGHT = 240;
	double error1 = 0;
	double time1 = 0;
	int whiteness[IMG_WIDTH]; // stores whiteness of each pixel 
	int index[IMG_WIDTH]; // a multiplication matrix of shifted array index values
	const double div = 3243600; // maximum possible value of index[] * whiteness[]
	public:
	
	// returns proportional error value from -1 to 1 
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
		// these are experimentally determined values here... the line tends to be ~64 pixels wide
		if(blackCount > 40 && blackCount < 70){
			return true;
		}
		return false;
	}
	
	// returns derivative of error value 	
	double getDeriv(double e){
		double error = e; // stores error in variable for safekeeping
		long time = getTime(); // stores current timestamp
		double deriv = (error - error1)/(time - time1); // compute derivative (dividing double by long - doesnt seem to cause problems??)
		//printf("Error: %f Time: %ld\n", error, time);
		//cout << "Deriv: " << deriv << endl;
		error1 = error; // set previous error to current error (for use in the next iteration)
		time1 = time; // set previous time to current time
		return deriv;
	}
};

class motor{
	private:
	const double setPoint = 47; // set point speed (both motors stopped)
	double baseLeft = setPoint + 9; // this is base value for motor 5
	double baseRight = setPoint - 9; // this is base value for motor 1 (note that it tends to run 2 slower than motor 5)
	
	public:
	// sets motor speeds according to error
	void followLine(double adj){
		// this block of code is a work in progress 
		double vLeft = baseLeft + adj;
		double vRight = baseRight + adj;
		set_motors(1,vRight);
		set_motors(5,vLeft);
		hardware_exchange();
	}
	void goBack(){
		double vLeft = baseRight;
		double vRight = baseLeft;
		set_motors(1,vRight);
		set_motors(5,vLeft);
		hardware_exchange();
		sleep1(100);
	}
	
};

int main(){
	// initial setup
	int err;
	cout<<" Hello"<<endl;
	err = init(0);
	cout<<"After init() error="<<err<<endl;
	open_screen_stream();

	// create instances of classes
	camera cam;
	motor mot;
	
	// constants need to be determined (and maybe moved to a different place?)
	double Kd = 0;
	double Kp = 20;
	
	// calls openGate and proceeds if gate opens (only used in actual operation)
	//if(openGate()){ 
	
		// begin main loop
		int count = 0;
		while(count < 100){
			take_picture();
			update_screen();
			
			double error = cam.getError(); // calls getError() method and stores error result in variable 
			double adjust = Kp * error + Kd * cam.getDeriv(error); // calculates motor adjustment value from error and its derivative
			cout << adjust << endl;

			if(cam.lineCheck()){
				mot.followLine(adjust); // pass the adjustment to motor control
			}
			else{
				mot.goBack();              
			}

			count++;
			sleep1(100);		
		}
	
	//} open gate bracket
}
