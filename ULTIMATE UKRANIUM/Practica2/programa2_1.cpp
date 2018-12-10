
#include <iostream>
#include "Fecha.h"

using namespace std;

int main()
{
	Fecha a, b, c(21, 9, 1988);
	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();

	int convierte = c.convierte();
	cout << "\n\n - Conversion de fecha: " << convierte;

	//¿Cuantos años hay del año 1 al año 2018?
	int nanios = 0;

	for(int i = 1; i <= 2018; i++) {
		bool b = c.leapyr(i);
		if(b) nanios++;
	}

	cout << "\n\n - Anios bisiestos (1 - 2018): " << nanios;

}