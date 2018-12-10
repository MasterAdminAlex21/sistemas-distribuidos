#include <iostream>
#include "Temperatura.h"
using namespace std;

int main(){
	
	Temperatura test;
	test.setTempKelvin( 300.5 );
	test.imprimeCelsius();
	test.setTempFahrenheit( 96 );
	test.imprimeKelvin();
	test.setTempCelsius( 36 );
	test.imprimeFahrenheit();

	return 0;	
}