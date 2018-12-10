
#include <iostream>
#include <math.h>
#include "Coordenada.h"

using namespace std;

#define PI 3.14159265

/*Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{
	
}*/

Coordenada::Coordenada(double a, double r)
{
	x = r * cos((a));
	y = r * sin((a));
}

double Coordenada::obtenerX()
{
	return x;
}

double Coordenada::obtenerY()
{
	return y;
}
