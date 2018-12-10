/*
Parámetros:
	1. Nombre del archivo.
	2. Número de partes a enviar.
	3. Ip del servidor.
*/
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Archivo.h"
#include <stdlib.h>
using namespace std;

int serv = 8000;
int puerto = 7200;

int main( int argc, char *argv[] ){	
	string ip = argv[3];
	int N = atoi( argv[2] );
	Archivo *arc = new Archivo( argv[1], O_RDONLY );
	SocketDatagrama *socket = new SocketDatagrama( puerto );
	
	PaqueteDatagrama *paquete = new PaqueteDatagrama( (char *)&N, sizeof(int), ip , serv );
	socket->envia( *paquete );

	size_t aux;
	while( N-- ){
		aux = arc->lee(100);
		paquete = new PaqueteDatagrama( (char *)(arc->get_contenido()), aux, ip , serv );
		socket->envia( *paquete );
	}
	arc->cerrar();
	return 0;
}