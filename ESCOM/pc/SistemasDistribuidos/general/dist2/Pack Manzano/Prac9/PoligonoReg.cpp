#include "PoligonoReg.h"
#include <cmath>
#define pb push_back
using namespace std;

const double PI = acos(-1.0);

PoligonoReg::PoligonoReg( int l ){
	lados = l;

	double angulo = (2*PI) / lados;
	double actual = 0;

	for( int i = 0; i < lados; i++ ){
		anadeVertice( Coordenada( cos( actual ) , sin( actual ) ) );
		actual += angulo;
	}
}

double PoligonoReg::obtieneArea(){
	double l = sqrt( pow( vertices[0].obtenerX() - vertices[1].obtenerX() , 2 ) + pow( vertices[0].obtenerY() - vertices[1].obtenerY() , 2 ) );
	double apotema = sqrt( 1 - (l*l / 4.0));
	double area = 0.5 * apotema * l * lados;
	return area;
}

float PoligonoReg::obtieneAreaF(){
	float l = sqrt( pow( vertices[0].obtenerX() - vertices[1].obtenerX() , 2 ) + pow( vertices[0].obtenerY() - vertices[1].obtenerY() , 2 ) );
	float apotema = sqrt( 1 - (l*l / 4.0) );
	float area = 0.5 * apotema * l * lados;
	return area;
}
