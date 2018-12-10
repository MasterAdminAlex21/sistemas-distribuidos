#include "PaqueteDatagrama.h"
#include "stdc++.h"
#define SIZEDEFAULT 3000
using namespace std;
PaqueteDatagrama::PaqueteDatagrama(char *C, unsigned int len, char *IP, int port){
	datos = (char*) malloc(sizeof(C) * sizeof(char));
	strcpy(datos, C);
	longitud = len;
	strcpy(ip, IP);
	puerto = port;

}
PaqueteDatagrama::PaqueteDatagrama(unsigned int len){
	datos = (char*)malloc(sizeof(len) * sizeof(char)), longitud = SIZEDEFAULT;
}
/*PaqueteDatagrama::~PaqueteDatagrama(){
	delete [] datos;
}*/
char* PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}
int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}
char *PaqueteDatagrama::obtieneDatos(){
	return datos;
}
void PaqueteDatagrama::inicializaPuerto(int P){
	puerto = P;
}
void PaqueteDatagrama::inicializaIp(char *X){
	strcpy(ip, X);
}
void PaqueteDatagrama::inicializaDatos(char *X){
	strcpy(datos, X);
}