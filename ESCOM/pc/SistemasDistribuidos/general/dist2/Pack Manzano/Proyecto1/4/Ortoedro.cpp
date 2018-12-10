#include "Ortoedro.h"
#include <set>
using namespace std;

Ortoedro::Ortoedro(Coordenada r1, Coordenada r2){
	Coordenada r3(r1.obtenerX(), r1.obtenerY(), r2.obtenerZ());
	Coordenada r4(r1.obtenerX(), r2.obtenerY(), r2.obtenerZ());
	Coordenada r5(r1.obtenerX(), r2.obtenerY(), r1.obtenerZ());
	Coordenada r6(r2.obtenerX(), r1.obtenerY(), r1.obtenerZ());
	Coordenada r7(r2.obtenerX(), r1.obtenerY(), r2.obtenerZ());
	Coordenada r8(r2.obtenerX(), r2.obtenerY(), r1.obtenerZ());
	rec[0] = Rectangulo(r6,r1,r5,r8);
	rec[1] = Rectangulo(r6,r7,r3,r1);
	rec[2] = Rectangulo(r8,r2,r4,r5);
	rec[3] = Rectangulo(r1,r3,r4,r5);
	rec[4] = Rectangulo(r6,r7,r2,r8);
	rec[5] = Rectangulo(r7,r3,r4,r2);
	/*
	cero <--> tres
	uno <--> cuatro
	dos <--> cinco
	*/
}

set< Coordenada > Ortoedro::getVertices(){
	set < Coordenada > aux, temp;
	for( int i = 0; i < 6; i++ ){
		temp = rec[i].getVertices();
		aux.insert( temp.begin(), temp.end() );
	}
	return aux;
}

double Ortoedro::getArea(){
	double area = 0.0;
	for(int i = 0; i < 6; i++){
		area += rec[i].getArea();
	}
	return area;
}

double Ortoedro::getVolumen(){
	Coordenada r1 = rec[3].getUno();
	Coordenada r2 = rec[2].getDos();
	return ( r2.obtenerZ() - r1.obtenerZ() ) * ( r2.obtenerY() - r1.obtenerY() ) * ( r2.obtenerX() - r1.obtenerX() );
}