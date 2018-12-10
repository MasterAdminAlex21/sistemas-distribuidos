/*
	Parámetros:
	1. Número telefónico del que se generará el reporte.
*/

#include <iostream>
#include <string.h>
#include <iomanip>
#include <string>
#include "Archivo.h"
using namespace std;

struct sms {
	int id;
	int origen;
	string telOrig;
	string telDest;
	string cdOrig;
	string cdDest;
	string fecha;
	string hora;
	char mensaje[165];
};

int main( int argc, char *argv[] ){

	int lee;
	string tel = argv[1];
	char nombre[100];
	sms msj;

	cout << endl;
	cout << "Para el número telefónico " << tel << " se tienen los siguientes registros:" << endl;
	cout << "Fecha\t\tHora\tCd. Origen\t\tTel. Marcado\tCd. Destino"<<endl;
	for( int i = 0; i < 32; i++ ){
		sprintf ( nombre, "%d.dat", i+1 );
		Archivo temp( nombre, O_RDONLY );
		while( (lee = temp.lee( sizeof( sms ) )) ){
			memcpy( &msj, temp.get_contenido(), lee );
			if( tel == msj.telOrig ){
				cout << msj.fecha << "\t" << msj.hora << "\t" << setw(21) << left << msj.cdOrig << "\t" << msj.telDest << "\t" << msj.cdDest <<endl;
			}
		}
	}
	cout << endl;

	return 0;
}