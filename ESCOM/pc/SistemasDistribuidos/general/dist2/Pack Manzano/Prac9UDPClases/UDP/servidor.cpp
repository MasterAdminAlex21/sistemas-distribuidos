#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
using namespace std;

int puerto = 8000;

int main(){

	int num[ 2 ];
	PaqueteDatagrama paquete( 2*sizeof(int)+ 5 );
	SocketDatagrama *socket = new SocketDatagrama( puerto );

	while(1){
		cout << "Esperando Cliente\n";
		int tam = socket->recibe( paquete );
		cout << "Cliente recibido\n";
		memcpy( num, paquete.obtieneDatos(), tam );
		int res = num[0] + num[1];
		string ip = paquete.obtieneDireccion();
		int pto = paquete.obtienePuerto();
		//cout << htons(pto)<<endl;
		PaqueteDatagrama enviar = PaqueteDatagrama( (char *) &res , sizeof(int), ip, htons(pto) );
		int env = socket->envia( enviar );
		if (env == -1){
		  printf("Error: %s (%d)\n", strerror(errno), errno);
		  exit(1);
		}
		cout << "Respuesta enviada \n";
	}

	return 0;
}