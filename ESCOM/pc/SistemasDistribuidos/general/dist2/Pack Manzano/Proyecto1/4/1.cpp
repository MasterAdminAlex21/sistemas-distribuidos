#include <iostream>
#include <set>
#include "Ortoedro.h"
using namespace std;

int main(){
	Ortoedro ort = Ortoedro( Coordenada( 1, 1, 1 ), Coordenada(2, 2, 3 ) );

	set< Coordenada > ver = ort.getVertices();

	cout << "Area: " << ort.getArea() << "\n";
	cout << "Volumen: " << ort.getVolumen() << "\n\n";

	int i = 1;
	for( set< Coordenada >::iterator it = ver.begin(); it != ver.end(); it++, i++ ){
		cout << "Vértice " << i << " x: " << (*it).obtenerX() << " y: " << it->obtenerY() << " z: " << it->obtenerZ() << "\n";
	}

	return 0;
}