#include "fecha.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

fecha::fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa)
{

	if((dia < 1) || (dia > 31)){
		cout << "Valor ilegal para el dia!\n";
		exit(1);
	}

	if((mes < 1) || (mes > 12)){
		cout << "Valor ilegal para el Mes!\n";
		exit(1);
	}

	if((anio < 0) || (anio > 2018)){
		cout << "Valor ilegal para el anio!\n";
		exit(1);
	
	}
}

void fecha::inicializarFecha(int dd, int mm, int aaaa) /*: dia(dd), mes(mm), anio(aaaa)*/{
 return;
}

void fecha::muestraFecha(){
 cout << "la fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
 return;
}

int fecha::convierte(){
 //int numero=
 return anio*10000+mes*100+dia;
 //return numero;
}

bool fecha::leapyr(){
 if(anio%4==2){
  return true;
 }
 else return false;
}

int main(){
 fecha a,b,c(31,15,2018);
 b.inicializarFecha(17,6,2002);
 a.muestraFecha();
 b.muestraFecha();
 c.muestraFecha();
 cout << "ejercicio sobre fecha b" << endl;
 cout << "fecha convertida: " << b.convierte() <<endl;
 cout << "b es año bisiesto: " << b.leapyr() <<endl;
 cout << "c es año bisiesto: " << c.leapyr() <<endl;
 
 int i=2018,cont=0;

 for(i;i>1;i--){
  if(i%4==0 && (i%100!=0 || i%400==0)){
   cont+=1;
  }
 }

 cout << "Años Bisiestos totales entre 0 y 2018: " << cont << endl;

}
