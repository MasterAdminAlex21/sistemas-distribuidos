#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <new>
#include <iostream>
#include <errno.h>
#include "PaqueteDatagrama.h"
using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char * dir, unsigned int length, char * data, int port){
	datos = new char[length];
	datos = data;
	strcpy(ip, dir);
	puerto = port;
	longitud = length;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int length){
	datos = new char[length];
	longitud = length;
}

char * PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

char * PaqueteDatagrama::obtieneDatos(){
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int port){
	puerto = port;
}

void PaqueteDatagrama::inicializaIp(char * dir){
	strcpy(ip, dir);
}

void PaqueteDatagrama::inicializaDatos(char * data){
	datos = data;
}
