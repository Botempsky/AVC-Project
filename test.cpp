#include "E101.h"
#include <iostream>
using namespace std;

int main()
{
  int err;
  cout<<" Hello"<<endl;
  err = init(0);
  cout<<"After init() error="<<err<<endl;
  
  set_motors(5,52);
  
  
  
    
  
  hardware_exchange();
   take_picture();
	 update_screen();
	 //sleep1(10);
     
	 
  
  return 0;
}
