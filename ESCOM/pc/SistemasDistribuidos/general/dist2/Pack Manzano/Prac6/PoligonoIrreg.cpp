#include "PoligonoIrreg.h"
#include <iostream>
#include <iterator>
#define pb push_back
using namespace std;

int PoligonoIrreg::veces = 0;

PoligonoIrreg::PoligonoIrreg()
{
	pos = 0;
}

void PoligonoIrreg::imprimeVertices()
{
	cout << "El polígono tiene "<< vertices.size() <<" vértices.\n";
	for( vector< Coordenada >::iterator it = vertices.begin(); it != vertices.end(); it++ ){
		cout << "x = " << it->obtenerX() << " y = " << it->obtenerY()<<" magnitud = " << it->obtenerMagnitud()<<"\n";
	}
}

void PoligonoIrreg::anadeVertice( Coordenada coor ){
	vertices.pb( coor );
}

int PoligonoIrreg::getVeces(){
	return veces;
}

void PoligonoIrreg::ordenaA(){
	sort( vertices.begin(), vertices.end() );
}