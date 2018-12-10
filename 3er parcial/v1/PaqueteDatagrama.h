#include <iostream>

using namespace std;


#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_


class PaqueteDatagrama
{
private:
	char *datos; //almacena los datos
	unsigned char ip[16]; //almacena la IP
	unsigned int longitud; //almacena la longitud de la cadena de datos
	int puerto; //Almacena el puerto

public:
	PaqueteDatagrama( char * d, unsigned int size,  unsigned char * i, int p); //cadena, longitud, direccion, puerto
	PaqueteDatagrama(unsigned int size); //crea un mensaje vacio con longitud determinada
	~PaqueteDatagrama();
	unsigned char * obtieneDireccion(); //regresa la direccion IP de la maquina a la cual se envia
	int obtienePuerto(); //regresa el puerto en el host remoto
	unsigned int obtieneLongitud();
	char *obtieneDatos(); 
	void inicializaPuerto(int);
	void inicializaIp(unsigned char *);
	void inicializaDatos(char *);
	void inicilizaLongitud(unsigned int size);


	
};

 #endif