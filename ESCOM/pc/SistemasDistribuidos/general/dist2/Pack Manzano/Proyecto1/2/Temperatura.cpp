#include "Temperatura.h"
#include <iostream>
using namespace std;

void Temperatura::setTempKelvin( double temp ){
	kelvin = temp;
}

void Temperatura::setTempFahrenheit( double temp ){
	kelvin = (( temp - 32 ) / 1.8 ) + 273.15;
}

void Temperatura::setTempCelsius( double temp ){
	kelvin = temp + 273.15;
}

void Temperatura::imprimeKelvin(){
	cout << kelvin <<" ºK\n";
}

void Temperatura::imprimeFahrenheit(){
	cout << ((kelvin - 273.15) * 1.8 ) + 32 << " ºF\n";
}

void Temperatura::imprimeCelsius(){
	cout << kelvin-273.15 << " ºC\n";
}