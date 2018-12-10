#include "Coordenada.h"
#include <iostream>
#include <cmath>

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) {
	magnitud = sqrt( x*x + y*y );
}

double Coordenada::obtenerX()
{
return x;
}

double Coordenada::obtenerY()
{
return y;
}

double Coordenada::obtenerMagnitud()
{
return magnitud;
}

bool Coordenada::operator<(const Coordenada &uno) const{
	return magnitud < uno.magnitud;
}