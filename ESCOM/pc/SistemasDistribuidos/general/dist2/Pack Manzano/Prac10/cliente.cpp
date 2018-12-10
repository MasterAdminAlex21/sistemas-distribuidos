#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Archivo.h"
#include "header.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <set>

int puerto = 8002;
set < char* > conj;

int main( int argc, char *argv[] ){

	int pto = atoi( argv[ 2 ] );
	PaqueteDatagrama *paquete;
	SocketDatagrama *socket = new SocketDatagrama( puerto );

	Archivo *arc = new Archivo(  argv[3] , O_WRONLY|O_TRUNC|O_CREAT, 0666 );

	messageCS envia;
	messageSC recibe;

	envia.offset = 0;
	envia.opcode = READ;
	envia.count = BUF_SIZE;
	strcpy( envia.name, argv[3] );
	//socket->setTimeout( 0, 250000 );
	socket->setRTO();
	while( 1 ){

		paquete =  new PaqueteDatagrama( (char *) &envia , sizeof( messageCS ), argv[1] , pto );
		int env = socket->enviaTimeoutRTO( *paquete );
		
		paquete = new PaqueteDatagrama( sizeof( messageSC ) );
		//int tam = socket->recibeTimeoutRTO( *paquete );
		int tam = socket->recibe( *paquete );

		if( tam < 0 ){
			continue;
		}

		memcpy( &recibe, paquete->obtieneDatos(), tam );

		if( recibe.result != OK ){
			cout << "Error recibiendo" << endl;
			continue;
			//exit(1);
		}

		if( recibe.count == 0 ){
			break;
		}

		if( recibe.result == OK && tam > 0 ){
			envia.offset += recibe.count;
			arc->escribe( recibe.data, recibe.count );	
		}
	}

	arc->cerrar();
	cout << "Archivo recibido de manera exitosa: " << envia.offset << " bytes" <<endl;

	return 0;
}