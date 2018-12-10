#include "Coordenada.h"
#include <iostream>

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) { }

double Coordenada::obtenerX()
{
return x;
}

double Coordenada::obtenerY()
{
return y;
}