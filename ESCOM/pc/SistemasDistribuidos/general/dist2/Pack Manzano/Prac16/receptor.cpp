#include "SocketMulticast.h"
using namespace std;

int main( int argc, char* argv[] ){

	char cad[4];
	SocketMulticast *sm = new SocketMulticast( atoi(argv[2]) );
	PaqueteDatagrama *paquete = new PaqueteDatagrama( sizeof( char ) * 3 + 1 );
	int tam = sm->recibe( *paquete, argv[1] );
	memcpy( cad, paquete->obtieneDatos(), tam );
	cout << "Cadena: " << cad <<endl;
	cout << "Ip emisor: " << paquete->obtieneDireccion()<<endl;
	cout << "Puerto emisor: " << paquete->obtienePuerto()<<endl;

	return 0;
}