#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa){
	aaaammdd = aaaa * 10000 + mm * 100 + dd;
}

Fecha::Fecha( long yyyymmdd ): aaaammdd(yyyymmdd){
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
	Fecha( dd , mm , aaaa );
 	return;
}

void Fecha::muestraFecha()
{
 cout << "La fecha es(aaaammdd): " << aaaammdd << "\n";
 return;
}