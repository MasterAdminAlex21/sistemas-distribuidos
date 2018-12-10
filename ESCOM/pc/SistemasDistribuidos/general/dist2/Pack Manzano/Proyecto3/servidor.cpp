#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Archivo.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <cmath>
#define pb push_back
using namespace std;

int puerto = 8000;

int main(){
	srand( time(NULL) );
	int N = 0;
	string aux, s;
	char nombre[100];
	vector< Archivo > arc;
	vector< string > palabras;

	PaqueteDatagrama *paquete = new PaqueteDatagrama( sizeof(int) + 3 );
	SocketDatagrama *socket = new SocketDatagrama( puerto );
	
	int tam = socket->recibe( *paquete );
	memcpy( &N, paquete->obtieneDatos(), tam );

	for( int i = 0; i < N; i++ ){
		sprintf ( nombre, "%d.txt", i+1 );
		Archivo temp = Archivo( nombre, O_WRONLY|O_TRUNC|O_CREAT, 0666 );
		arc.pb( temp );
	}

	for( int i = 0; i < N; i++ ){
		paquete = new PaqueteDatagrama( 100 );
		tam = socket->recibe( *paquete );
	 	aux = paquete->obtieneDatos();
		
		palabras.clear();
		stringstream ss( aux );
		while (ss >> s) {
		    palabras.pb( s );
		}
		ss.clear();

		s = "";
		if( palabras.size() > 0 ){
			s = palabras[ rand()%palabras.size() ];
		}
		arc[i].escribe( s.c_str(), s.size() );
		arc[i].cerrar();
	}
}