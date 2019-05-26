#include <iostream>
#include "E101.h"
using namespace std;

int main(){
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;

	set_motors(1,47);
	set_motors(5,47);
	hardware_exchange();
		
}
