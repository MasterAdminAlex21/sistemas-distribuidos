#ifndef _PAQUETEDATAGRAMA_H_
#define _PAQUETEDATAGRAMA_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;

class PaqueteDatagrama {
	public:
		PaqueteDatagrama(char *, unsigned int, char *, int );
		PaqueteDatagrama(unsigned int );
		~PaqueteDatagrama();
		char *obtieneDireccion();          
		unsigned int obtieneLongitud();
		int obtienePuerto();
		char *obtieneDatos();
		void inicializaPuerto(int);
		void inicializaIp(char *);
		void inicializaDatos(char *);
	private:
		char *datos; 			//Almacena los datos
		char ip[16]; 			//Almacena la IP 
		unsigned int longitud;	//Almacena la longitude de la cadena de datos
		int puerto;    			//Almacena el puerto
};  

#endif