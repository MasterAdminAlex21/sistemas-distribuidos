#ifndef PAQUETEDATAGRAMA
#define PAQUETEDATAGRAMA

#include <iostream>
#include <string.h>

class PaqueteDatagrama{

public:
	PaqueteDatagrama(char *, unsigned int, char *, int);
	PaqueteDatagrama(unsigned int);
	~PaqueteDatagrama();
	char *obtieneDireccion();
	unsigned int obtieneLongitud();
	int obtienePuerto();
	char *obtieneDatos();
	void inicializaPuerto(int);
	void inicializaIP(char *);
	void inicializaDatos(char *);

private:
	char *datos;
	char ip[16];
	unsigned int longitud;
	int puerto;
};

#endif