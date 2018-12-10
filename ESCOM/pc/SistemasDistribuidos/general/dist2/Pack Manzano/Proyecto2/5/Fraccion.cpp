#include "Fraccion.h"
#include <iostream>
#include <string>
using namespace std;

Fraccion::Fraccion( int num, int den ) : numerador(num), denominador(den){
}

double Fraccion::getValorReal(){
	return (double)numerador/(double)denominador;
}

void Fraccion::setFraccion( int num, int den ){
	numerador = num;
	denominador = den;
}

void Fraccion::imprimeFraccion(){
	string aux = ((double)numerador/(double)denominador < 0 ? "-" : "");
	aux += to_string(abs( numerador));
	aux += "/";
	aux += to_string(abs(denominador));
	cout << aux << "\n";
}

Fraccion Fraccion::getReducida(){
	int gcd = __gcd( numerador, denominador );
	return  Fraccion( numerador/gcd , denominador/gcd );
}

Fraccion Fraccion::operator+( Fraccion& dos ){
	return Fraccion( numerador * dos.denominador + denominador * dos.numerador, 
					denominador * dos.denominador );
}

Fraccion Fraccion::operator-( Fraccion& dos ){
	return Fraccion( numerador * dos.denominador - denominador * dos.numerador, 
					denominador * dos.denominador );
}

Fraccion Fraccion::operator*( Fraccion& dos ){
	return Fraccion( numerador * dos.numerador , denominador * dos.denominador );
}

Fraccion Fraccion::operator/( Fraccion& dos ){
	return Fraccion( numerador * dos.denominador , denominador * dos.numerador );
}