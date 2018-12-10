#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <stdlib.h>
#include <set>
#include <cstring>
using namespace std;

int serv = 7200;
int puerto = 8000;
 
int main( int argc, char *argv[] ){

	int num[ 2 ];
	num[0] = 5; num[1] = 30;

	PaqueteDatagrama *paquete;
	paquete = new PaqueteDatagrama( (char *)num, 2*sizeof(int), argv[1] , serv );
	SocketDatagrama *socket = new SocketDatagrama( puerto );
	socket->setBroadcast();

	int tam = socket->envia( *paquete );

	set< string > ips;
	while(1){
		paquete = new PaqueteDatagrama( sizeof(int) );
		tam = socket->recibe( *paquete );
		int res;
		memcpy( &res, paquete->obtieneDatos(), tam );
		cout << paquete->obtieneDireccion()<<endl;
	}
	
	return 0;
}