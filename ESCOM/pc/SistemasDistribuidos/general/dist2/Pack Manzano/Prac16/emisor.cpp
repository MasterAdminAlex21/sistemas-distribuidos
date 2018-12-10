#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char*argv[]){

	SocketMulticast socket( atoi(argv[1]) );
	PaqueteDatagrama pack(argv[3], strlen(argv[3]), argv[1], atoi(argv[2]));

	while(true)	
		cout << socket.envia(pack, *argv[4]) << endl;

}
