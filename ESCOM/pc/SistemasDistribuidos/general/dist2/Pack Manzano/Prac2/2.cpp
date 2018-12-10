#include <iostream>
#include "Fecha.cpp"
using namespace std;

int main(){
	Fecha a, b, c(21, 9, 2000);
	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();

	cout << (c.leapyr() ? "Es bisiesto" : "No es bisiesto" ) <<endl;

	return 0;	
}