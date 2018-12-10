#include "PaqueteDatagrama.h"

PaqueteDatagrama :: PaqueteDatagrama(char *d, unsigned int l, char *IP, int p){	
	longitud = l;
	puerto = p;
	datos = new char[l];
	memcpy(datos, d, l);
	strcpy(ip, IP);
}

PaqueteDatagrama :: PaqueteDatagrama(unsigned int l){
	longitud = l;
	datos = new char[l]();
}

PaqueteDatagrama :: ~PaqueteDatagrama(){
	delete datos;
	longitud = 0;
	puerto = 0;
}

char * PaqueteDatagrama :: obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama :: obtieneLongitud(){
	return longitud;
}

int PaqueteDatagrama :: obtienePuerto(){
	return puerto;
}

char * PaqueteDatagrama :: obtieneDatos(){
	return datos;
}

void PaqueteDatagrama :: inicializaPuerto(int p){
	puerto = p;
}

void PaqueteDatagrama :: inicializaIP(char * IP){
	strcpy(ip, IP);
}

void PaqueteDatagrama :: inicializaDatos(char *d){
	memcpy(datos, d, longitud);	
}

