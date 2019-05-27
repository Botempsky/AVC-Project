#include <iostream>
#include "E101.h"
using namespace std;

int main(){
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;

	set_motors(1,52);
	set_motors(5,43);
	hardware_exchange();
		
}
