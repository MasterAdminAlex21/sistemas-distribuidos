#include "Rectangulo.h"
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

Rectangulo::Rectangulo(){ 
	coord[0] = Coordenada(0,0);
	coord[1] = Coordenada(0,0);
	coord[2] = Coordenada(0,0);
	coord[3] = Coordenada(0,0);
}

Rectangulo::Rectangulo( Coordenada uno, Coordenada dos, Coordenada tres, Coordenada cuatro){
	coord[0] = uno;
	coord[1] = dos;
	coord[2] = tres;
	coord[3] = cuatro;
}

set< Coordenada > Rectangulo::getVertices(){
	set < Coordenada > aux;
	for( int i = 0; i < 4; i++ ){
		aux.insert( coord[i] );
	}
	return aux;
}

double Rectangulo::getArea(){
	double width = (coord[0].obtenerZ()-coord[3].obtenerZ())*(coord[0].obtenerZ()-coord[3].obtenerZ());
	width += (coord[0].obtenerX()-coord[3].obtenerX())*(coord[0].obtenerX()-coord[3].obtenerX());
	width += (coord[0].obtenerY()-coord[3].obtenerY())*(coord[0].obtenerY()-coord[3].obtenerY());
	width = sqrt(width);

	double height = (coord[0].obtenerY()-coord[1].obtenerY())*(coord[0].obtenerY()-coord[1].obtenerY());
	height += (coord[0].obtenerX()-coord[1].obtenerX())*(coord[0].obtenerX()-coord[1].obtenerX());
	height += (coord[0].obtenerZ()-coord[1].obtenerZ())*(coord[0].obtenerZ()-coord[1].obtenerZ());
	height = sqrt(height);
	
	return height * width;
}

Coordenada Rectangulo::getUno(){
	return coord[0];
}

Coordenada Rectangulo::getDos(){
	return coord[1];
}