#include "Servidor.h"

Servidor::Servidor( int n_, int porc_, int opc_ ) : n(n_), porc( porc_ ), opc(opc_){
	Generador gen( n, opc );
	int port = 7200+n;
	double tiempoBase = double(125000 * 100) / (double)porc;

	if( tiempoBase > 0 && fork() == 0 ){
		while(1){
			sleep( (int)(tiempoBase / 1000000.0) );
			usleep( (int)tiempoBase % 1000000 );
			gen.genera();
		}
	}

	PaqueteDatagrama *paquete = new PaqueteDatagrama( sizeof( peticion ) );
	SocketDatagrama *socket = new SocketDatagrama( port );

	peticion pet;
	respuesta *res;

	while( 1 ){
		res = new respuesta;
		paquete = new PaqueteDatagrama( sizeof( peticion ) );
		int tam = socket->recibe( *paquete );
		memcpy( &pet, paquete->obtieneDatos(), tam );

		res->tipo = pet.tipo;
		if( pet.tipo == 1 ){
			cuentaVotos( res );
		}
		else{
			busca( res, pet.buscar );
		}
		cout << "Servidor " << n << " respondió petición"<<endl;

		paquete = new PaqueteDatagrama( (char *) res , sizeof(respuesta), paquete->obtieneDireccion(), paquete->obtienePuerto() );
		int env = socket->envia( *paquete );
	}
}

void Servidor::cuentaVotos( respuesta *res ){
	int lee;
	voto v;
	registro aux;
	char nombre[100];
	map< string, int > mapa;
	sprintf ( nombre, "%d.txt", n );
	Archivo temp( nombre, O_RDONLY );
	
	while( (lee = temp.lee( sizeof( registro ) )) ){
		memcpy( &aux, temp.get_contenido(), lee );
		mapa[ aux.partido ]++;
	}
	temp.cerrar();

	int i = 0;
	for( map< string, int >::iterator it = mapa.begin(); it != mapa.end(); it++  ){
		v.partido = it->first;
		v.num = it->second;
		res->v[i++] = v;
	}
}

void Servidor::busca( respuesta *res, string buscar ){
	int lee;
	registro aux;
	char nombre[100];
	sprintf ( nombre, "%d.txt", n );
	Archivo temp( nombre, O_RDONLY );
	
	while( (lee = temp.lee( sizeof( registro ) )) ){
		memcpy( &aux, temp.get_contenido(), lee );
		if( aux.CURP == buscar || aux.celular == buscar ){
			res->partido = aux.partido;
			break;
		}
	}
	temp.cerrar();
}
