#include "gate.h"
#include <iostream>
#include "E101.h"

using namespace std;

void gate::openGate(){
	cout<<"Bingo"<<endl;
	char ipadd[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
	char request[24] = {'P','l','e','a','s','e'};
	char pass[24];
	connect_to_server(ipadd, 1024);
	send_to_server(request);
	receive_from_server(pass);
	send_to_server(pass);
   
}
