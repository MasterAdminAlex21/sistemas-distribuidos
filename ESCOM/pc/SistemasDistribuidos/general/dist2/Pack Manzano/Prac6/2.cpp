#include <iostream>
#include "Coordenada.h"
#include "Rectangulo.h"
#include "PoligonoIrreg.h"
#define pb push_back
using namespace std;

int main( )
{
	
	PoligonoIrreg pol;

	int N = 10;
	srand( time(NULL) );
	//Con push_back
	for( int i = 0; i < N; i++ ){
		double x = (rand() % 200000)/1000.0 - 100.0;
		double y = (rand() % 200000)/1000.0 - 100.0;
		pol.anadeVertice( Coordenada( x , y ));
	}
	pol.imprimeVertices();
	pol.ordenaA();
	pol.imprimeVertices();

	return 0;
} 