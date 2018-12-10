#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Archivo.h"
#include "header.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

int puerto = 8002;
 
int main( int argc, char *argv[] ){

	struct timeval tiempo1;
	struct timeval tiempo2;
	struct timeval tiempo3;

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
	socket->setTimeout();
	socket->setRTO(); 

	while( 1 ){
		
		gettimeofday(&tiempo1, NULL);
		tiempo2 = socket->getTimeout();
		timeradd( &tiempo1, &tiempo2, &tiempo3 );
		envia.timestamp = tiempo3;
		
		paquete = new PaqueteDatagrama( (char *) &envia , sizeof( messageCS ), argv[1] , pto );
		int env = socket->enviaTimeoutRTO( *paquete );
		
		paquete = new PaqueteDatagrama( sizeof( messageSC ) );
		int tam = socket->recibeTimeoutRTO( *paquete );

		if( tam < 0 ){
			continue;
		}
		memcpy( &recibe, paquete->obtieneDatos(), sizeof( messageSC ) );

		tiempo2 = socket->getTiempoRecibe();
		if( timercmp( &tiempo2, &(recibe.timestamp), > ) ){
			//cout << "Recibido: " << socket->getTiempoRecibe().tv_sec <<" " << socket->getTiempoRecibe().tv_usec <<endl;
			//cout << "Esperado: " << recibe.timestamp.tv_sec << " " << recibe.timestamp.tv_usec << endl;
			//cout << "No coincide tiempo\n";
			continue;
		}

		if( recibe.result != OK ){
			//cout << "Error recibiendo" << endl;
			continue;
			//exit(1);
		}

		if( recibe.count == 0 ){
			break;
		}

		if( recibe.result == OK && tam > 0 ){
			//cout << "Recibido offset: " << envia.offset << "\n";
			envia.offset += recibe.count;
			arc->escribe( recibe.data, recibe.count );	
		}
	}

	arc->cerrar();
	//cout << "Archivo recibido de manera exitosa: " << envia.offset << " bytes" <<endl;

	return 0;
}