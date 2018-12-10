#include <iostream>
#include "Coordenada.h"
#include "Rectangulo.h"
#include "PoligonoIrreg.h"
#define pb push_back
using namespace std;

int main( )
{
	
	PoligonoIrreg pol;
	/*
	pol.imprimeVertices();
	pol.anadeVertice( Coordenada(0 , 0 ));
	pol.anadeVertice( Coordenada(1 , 0 ));
	pol.imprimeVertices();
	*/

	vector < PoligonoIrreg > poligonos;

	//Con reserve
	for( int i = 0; i < 50; i++ ){
		int num = rand() % 1000000;
		PoligonoIrreg temp;
		for( int j = 0; j < num; j++ ){
			temp.anadeVertice( Coordenada(0 , 0) );
		}
		poligonos.resize( i + 10 );
		poligonos[ i ] = temp ;
	}
	cout << pol.getVeces()<<endl;

	return 0;
} 