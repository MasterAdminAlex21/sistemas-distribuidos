#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int l, char *dir, int p) {
	datos = new char[l];
	longitud = l;
	strcpy(ip,dir);
	puerto = p;
	memcpy(datos,dat,longitud);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int l) { 
	longitud = l;
	datos = new char[longitud];
}

PaqueteDatagrama::~PaqueteDatagrama() {
	delete[] datos;
}

char *PaqueteDatagrama::obtieneDireccion() {
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud() {
	return longitud;
}

int PaqueteDatagrama::obtienePuerto() {
	return puerto;
}

char *PaqueteDatagrama::obtieneDatos() {
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p) {
	puerto = p;
}

void PaqueteDatagrama::inicializaIp(char *dir) {
	strcpy(ip,dir);
}

void PaqueteDatagrama::inicializaDatos(char *dat) {
	longitud = sizeof(dat);
	memcpy(datos,dat,longitud);
}