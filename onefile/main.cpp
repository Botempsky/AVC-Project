#include <iostream>
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
			cout << error << endl;
		}
		return error/div;
	}
		
};


int main(){
	// initial setup
	int err;
	cout<<" Hello"<<endl;
	err = init(1);
	cout<<"After init() error="<<err<<endl;
	open_screen_stream();

	int count = 0;
	camera c;
	while(count < 1){
		take_picture();
		update_screen();
		cout << c.getError() << endl;
		count++;
	}
	
	
}
