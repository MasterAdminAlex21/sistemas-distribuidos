#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa)
{
 mes = mm;
 dia = dd;
 anio = aaaa;
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
 anio = aaaa;
 mes = mm;
 dia = dd;
 return;
}
void Fecha::muestraFecha()
{
 cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
 return;
}

bool Fecha::leapyr(){
	bool div4 = ( anio%4 == 0 ? true : false);
	bool div100 = ( anio%100 == 0 ? true : false );
	bool div400 = ( anio%400 == 0 ? true : false );

	if( ( div4 && !div100 ) || div400 ){
		return true;
	} 
	return false;
}