#include "PoligonoIrreg.h"
#include <iostream>
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
	for( int i = 0; i < vertices.size(); i++ ){
		cout << i+1 << ". x = " << vertices[i].obtenerX() << " y = " << vertices[i].obtenerY()<<"\n";
	}
}

void PoligonoIrreg::anadeVertice( Coordenada coor ){
	veces++;
	vertices.resize( pos + 5 );
	vertices[ pos++ ] = coor;
	//vertices.pb( coor );
}

int PoligonoIrreg::getVeces(){
	return veces;
}