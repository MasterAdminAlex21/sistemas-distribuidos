#include "PaqueteDatagrama.h"
#include <string>
#include <iostream>
using namespace std;

PaqueteDatagrama::PaqueteDatagrama( char * datos_, unsigned int longitud_, string ip_ , int puerto_ ){
	longitud = longitud_;
	datos = new char[ longitud ];
	memcpy( datos, datos_, longitud );
	ip = ip_;
	puerto = puerto_;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud_){
	longitud = longitud_;
	datos = new char[1];
}

PaqueteDatagrama::~PaqueteDatagrama(){
	delete datos;
}

string PaqueteDatagrama::obtieneDireccion(){
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

void PaqueteDatagrama::inicializaPuerto(int puerto_){
	puerto = puerto_;
}

void PaqueteDatagrama::inicializaIp(string ip_){
	ip = ip_;
}
void PaqueteDatagrama::inicializaDatos(char * datos_){
	datos = new char[ strlen(datos_) + 1 ];
	memcpy( datos, datos_, strlen( datos_ )+1 );
}
