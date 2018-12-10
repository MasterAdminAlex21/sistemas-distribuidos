#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa)
{
	dias[0] = "Sábado";
	dias[1] = "Domingo";
	dias[2] = "Lunes";
	dias[3] = "Martes";
	dias[4] = "Miércoles";
	dias[5] = "Jueves";
	dias[6] = "Viernes";
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
	Fecha( dd , mm , aaaa );
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

string Fecha::dayOfWeek(){
	int mm = mes, dd = dia, yy = anio, century, year, T, dayOfWeek;

	if( mm < 3 ){
		mm = mm + 12;
		yy--;
	}
	century = int( yy / 100);
	year = yy%100;
	T = dd + int( 26 * ( mm + 1 )/10 ) + year + int( year/4 ) + int( century/4 ) - 2*century;
	dayOfWeek = T%7;
	if (dayOfWeek < 0){
		dayOfWeek += 7;
	}
	return dias[ dayOfWeek ];
}