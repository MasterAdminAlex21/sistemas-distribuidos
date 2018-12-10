#include "Coordenada.h"
#include <iostream>

Coordenada::Coordenada(double xx, double yy, double zz) : x(xx), y(yy), z(zz) { }

const double Coordenada::obtenerX() const
{
	return x;
}

const double Coordenada::obtenerY() const
{
	return y;
}

const double Coordenada::obtenerZ() const{
	return z;
}

bool Coordenada::operator<(const Coordenada &uno) const{
	if( x != uno.x ) return x < uno.x;
	if( y != uno.y ) return y < uno.y;
	return z < uno.z;
}