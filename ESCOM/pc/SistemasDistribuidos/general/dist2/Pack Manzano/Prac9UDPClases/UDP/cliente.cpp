#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
using namespace std;

int serv = 8000;
int puerto = 7200;

int main(int argc, char *argv[]){

	int num[ 2 ];
	num[0] = 5; num[1] = 30;

	PaqueteDatagrama paquete( (char *)num, 2*sizeof(int), argv[1] , serv );
	SocketDatagrama *socket = new SocketDatagrama( puerto );

	int tam = socket->envia( paquete );
	cout << "Enviados "<<tam << " bytes\n";
	PaqueteDatagrama pack = PaqueteDatagrama( sizeof(int) + 10 );
	tam = socket->recibe( pack );
	cout << "Recibidos " << tam <<" bytes\n";
	int res;
	memcpy( &res, pack.obtieneDatos(), tam );
	cout << res << "\n"<<tam;

	return 0;
}