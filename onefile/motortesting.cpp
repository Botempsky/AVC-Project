#include <iostream>
#include "E101.h"
using namespace std;

int main(){
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;

	set_motors(1,37);
	set_motors(5,52);
	hardware_exchange();
		
}
