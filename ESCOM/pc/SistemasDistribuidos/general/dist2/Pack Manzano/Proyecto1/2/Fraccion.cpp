#include "Fraccion.h"
#include <iostream>
#include <string>
using namespace std;

Fraccion::Fraccion( int num, int den ) : numerador(num), denominador(den){
}

double Fraccion::getValorReal(){
	return (double)numerador/(double)denominador;
}

string Fraccion::getReducida(){
	int gcd = __gcd( numerador, denominador );
	string aux = (numerador/denominador < 0 ? "-" : "");
	aux += to_string(abs( numerador/gcd ));
	aux += "/";
	aux += to_string(abs(denominador/gcd));
	return  aux;
}