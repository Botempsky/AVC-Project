#include <iostream>
#include "E101.h"
using namespace std;

int main(){
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;
	
	double left = 47.0;
	double right = 47.0;
	set_motors(1,left);
	set_motors(5,right);
	hardware_exchange();
	
}
