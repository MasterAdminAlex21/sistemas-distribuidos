/*
	Parámetros:
	1. Número de mensajes a enviar de cada estado.
*/

#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Generador.h"
#include "Archivo.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <vector>
#include <unistd.h>
#include <set>
#define mp make_pair
#define pb push_back
#define par pair< long long, int >
using namespace std;

int main(int argc, char *argv[]){
	int N = atoi( argv[1] );
	int port = 7200;
	int res = 1;
	sms msj;
	PaqueteDatagrama *paquete = new PaqueteDatagrama( sizeof( sms ) );
	SocketDatagrama *socket = new SocketDatagrama( port );
	set < par > conj;
	par tmp;

	vector < Archivo > arc;
	char nombre[100];

	for( int i = 0; i < 32; i++ ){
		sprintf ( nombre, "%d.dat", i+1 );
		Archivo temp( nombre, O_WRONLY|O_TRUNC|O_CREAT, 0666 );
		arc.pb( temp );
	}

	for( int i = 0; i < 32; i++ ){
		if(fork() == 0){
			Generador gen( atoi( argv[1] ), i );
			exit(0);
		}
	}

	while( 1 ){
		paquete = new PaqueteDatagrama( sizeof(sms) );
		int tam = socket->recibe( *paquete );
		memcpy( &msj, paquete->obtieneDatos(), tam );
		tmp = mp( msj.id, msj.origen );

		if( !conj.count( tmp ) ){
			arc[ msj.origen ].escribe((char *) &msj, sizeof(sms) );
			conj.insert( tmp );
			//cout << conj.size()<<endl;
			//if( conj.size() == (N*32) ) cout << "Recibió todos"<<endl;
		}

		paquete =  new PaqueteDatagrama( (char *) &tmp , sizeof(par), paquete->obtieneDireccion(), paquete->obtienePuerto() );
		int env = socket->envia( *paquete );
	}

	return 0;
}