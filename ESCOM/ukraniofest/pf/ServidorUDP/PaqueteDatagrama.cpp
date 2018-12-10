#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int longi, char *ipp, int puert){
	//datos = dat;
	datos = new char[longi];
	memcpy(datos, dat, longi);
	longitud = longi;
	strcpy(ip, ipp);
	//ip = ipp;
	puerto = puert;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longi){
	datos = new char[longi];
	longitud = longi;
	//ip = NULL;
	//puerto= 0;
	//ip = ipp;
	//puerto = puert;
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete[] datos;
}

char* PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

char* PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int p){
	puerto = p;
}

void PaqueteDatagrama::inicializaIp(char *ipp){
	strcpy(ip, ipp);
}

void PaqueteDatagrama::inicializaDatos(char *dat){
	//delete [] datos;
	//datos = new char[longitud];
	memcpy(datos, dat, longitud);
}
		
		
		
		
		
		
