#include <string.h>
#include <iostream>
#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama( char * d, unsigned int size, unsigned char * i, int p) {
	longitud=size;
	datos=(char*)malloc(longitud);
	memcpy(datos,d,longitud);
	memcpy(ip,i,16);

	puerto=p;
}

PaqueteDatagrama::~PaqueteDatagrama(){
	//free(datos);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int size){
	longitud=size;
	datos=(char*)malloc(longitud);
	//cout<<"hi"<<endl;
}

unsigned char * PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

 int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

char * PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p){
	puerto=p;
}

void PaqueteDatagrama::inicializaIp(unsigned char * i){
	memcpy(ip,i,16);
}

void PaqueteDatagrama::inicializaDatos(char * d){
	memcpy(datos,d,longitud);
}
void PaqueteDatagrama::inicilizaLongitud(unsigned int size){
	longitud=size;
	datos=(char*)malloc(longitud);
}