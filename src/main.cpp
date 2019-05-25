#include <iostream>
#include "gate.h"
#include "motor.h"
#include "camera.h"
#include "E101.h"
using namespace std;

int main(){
	
	int err;
	cout << "Hello World" << endl;
	err = init(1);
	cout << "After init() err = " << err << endl;
	
    //error e;
    //cout << e.getError() << endl;
    cout << "hello world"<< endl;
    set_motors(1,48);
    set_motors(5,48);
    hardware_exchange();
}
