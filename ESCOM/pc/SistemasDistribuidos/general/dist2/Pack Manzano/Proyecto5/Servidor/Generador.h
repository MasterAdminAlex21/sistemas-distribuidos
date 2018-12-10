#ifndef GENERADOR_H_
#define GENERADOR_H_
#include "Archivo.h"
#include "Header.h"
#include <set>
#include <iostream>
#define PORCENTAJE 10 //porcentaje de fraude
using namespace std;

class Generador
{
public:
	Generador( int n_, int opc_ );
	void genera();
private:
	int n, opc, fraude, j;
	Archivo *arc;
	registro reg;
	string partidos[11];
	set <string> curp, telefono;
	string generaTel();
	string generaCurp();
};
#endif