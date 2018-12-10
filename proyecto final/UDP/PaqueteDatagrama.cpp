#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <iostream>

PaqueteDatagrama::PaqueteDatagrama(char * datoss, unsigned int longitudd, char *ipp, int puertoo): longitud(longitudd), puerto(puertoo){
	//datos = new char(longitudd);
	datos =(char*)malloc(longitudd*sizeof(char));
	memcpy(datos, datoss,longitudd*sizeof(char));
	memcpy(ip,ipp,(strlen(ipp)+1)*sizeof(char));
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitudd): longitud(longitudd){
	//datos = new char(longitudd);
	
	datos =(char*)malloc(longitudd*sizeof(char));
}

PaqueteDatagrama::~PaqueteDatagrama(){
	//delete datos;
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

void PaqueteDatagrama::inicializaPuerto(int puertoo){
	puerto=puertoo;
}

void PaqueteDatagrama::inicializaIp(char *ipp){
	memcpy(ip,ipp,strlen(ipp)+1);
}

void PaqueteDatagrama::inicializaDatos(char *datoss){
	memcpy(datos,datoss,strlen(datoss)+1);
}