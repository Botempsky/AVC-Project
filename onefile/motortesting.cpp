#include <iostream>
#include "E101.h"
using namespace std;

int main(){
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;
	
	
	
	set_motors(1,48); // Right motor - max 65
	set_motors(5,48); // Left motor - max 30
	hardware_exchange();
	
}
