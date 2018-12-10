#include "fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) {
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
cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
return;
 }

 int Fecha::convierte()
 {
 	 return this -> anio*10000+this ->mes*100+this ->dia;
 

 }