#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa)
{
	if((mes < 1) || (mes > 12)){
		cout << "Valor ilegal para el mes!\n";
		exit(1);
	}
	if( dia < 1 || dia > 31 ){
		cout << "Valor ilegal para el día!\n";
		exit(1);
	}
	if( anio > 2016 || anio<0 ){
		cout << "Valor ilegal para el año\n";
		exit(1);
	}
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