#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <cstdlib>
#include <map>
#include <cstring>
#define MAXPET 5
using namespace std;
#include "Header.h"

string identificar( string buscar ){
	for( int i = 0; i < buscar.size(); i++ ){
		if( buscar[i] < '0' || buscar[i] > '9' ){
			return "CURP";
		}
	}
	return "teléfono";
}

int puerto = 8000;	//Puerto del socket
int port = 7200;	//Puerto del servidor
char ip[] = "127.0.0.1";

int main( int argc, char* argv[] ){
	if( argc < 2 ){
		cout << "Forma de uso: programa tipo_petición parametros\n";
		cout << "Tipo 1: Número de votos totales\n";
		cout << "Tipo 2: Por quién ha votado un usuario, se tiene que agregar como parámetro la CURP o el número de teléfono\n";
		exit(0);
	}

	string buscar;
	int n = atoi( argv[1] );
	peticion pet;
	respuesta res;

	switch( n ){
		case 1:
			pet.tipo = 1;
		break;
		case 2:
			buscar = argv[2];
			pet.tipo = 2;
			pet.buscar = buscar;
		break;
		default:
			cout << "Tipo de consulta inválida"<<endl;
			exit(0);
	}

	int rec, cont = 0;
	map < string, int > mapa;
	string peticion2;
	SocketDatagrama *socket = new SocketDatagrama( puerto );
	PaqueteDatagrama *paquete;
	socket->setTimeout( 0, 125000 );

	for( int i = 0, j = 0; i < 8; i++ ){
		for( j = 0; j < MAXPET; j++ ){
			paquete = new PaqueteDatagrama( (char *)&pet, sizeof(peticion), ip, port+i );
			socket->envia( *paquete );

			paquete = new PaqueteDatagrama( sizeof(respuesta) );
			rec = socket->recibe( *paquete );
			if( rec >= 0 ) break;
		}
		if( j == MAXPET ){
			cout << "El servidor " << i << " no respondió" << endl;
			cont++;
		}
		else{
			memcpy( &res, paquete->obtieneDatos(), rec );

			if( pet.tipo == 1 ){
				for( int i = 0; i < 10; i++ ){
					if( res.v[i].partido != "" )
						mapa[ res.v[i].partido ] += res.v[i].num;
				}
			}
			else{
				if( res.partido != "" )
					peticion2 = res.partido;
			}

		}
	}
	
	if( cont == 8 ){
		cout << "Ningún servidor se encontró activo" <<endl;
		exit(0);
	}
	if( pet.tipo == 1 ){
		cout << "Los votos totales hasta ahora son: " << endl;
		for( map< string, int >::iterator it = mapa.begin(); it != mapa.end(); it++  ){
			cout << it->first << ": " << it->second << endl;
		}
	}
	else{
		cout << "El votante con " << identificar( buscar ) << " " << buscar << " ha votado por: " << peticion2 << endl;
	}

}