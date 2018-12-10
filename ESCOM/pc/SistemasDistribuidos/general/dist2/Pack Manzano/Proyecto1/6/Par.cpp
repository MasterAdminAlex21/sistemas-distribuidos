#include "Par.h"
#include <iostream>

Par::Par( int num , bool isP ) : numero(num), esPrimo(isP){
}

int Par::getNumero(){
	return numero;
}

bool Par::isPrimo(){
	return esPrimo;
}

void Par::setIsPrimo( bool val ){
	esPrimo = val;
}

void Par::setNumero( int val ){
	numero = val;
}