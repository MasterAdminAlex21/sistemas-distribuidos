#ifndef SERVIDOR_H_
#define SERVIDOR_H_
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Archivo.h"
#include "Generador.h"
#include "Header.h"
#include <cstdio>
#include <map>
#include <unistd.h>
#include <iostream>
using namespace std;

class Servidor{
public:
	Servidor( int n_, int porc_, int opc_ );
private:
	int n, porc, opc;
	void busca( respuesta *res, string buscar );
	void cuentaVotos( respuesta *res );
};
#endif