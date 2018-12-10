#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

class PaqueteDatagrama {
	public:
		
		PaqueteDatagrama(unsigned int );
		PaqueteDatagrama(char *, unsigned int, char *, int );
		~PaqueteDatagrama();
		char *obtieneDireccion();
		unsigned int obtieneLongitud();
		int obtienePuerto();
		char *obtieneDatos();
		void inicializaPuerto(int puertoo);
		void inicializaIp(char *);
		void inicializaDatos(char *);
	private:
		char *datos;		//Almacena los datos
		char ip[16];		//Almacena la IP
		unsigned int longitud;			//Almacena la longitude de la cadena de datos
		int puerto;			//Almacena el puerto
};

#endif