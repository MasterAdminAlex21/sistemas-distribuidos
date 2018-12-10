#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_
#include <stdint.h>
#include <string.h>
struct msj {
	uint32_t secuencia; //Numero de secuencia
	uint32_t solicitud[2]; //pareja de números enviados por el cliente para su suma
	uint32_t respuesta; //respuesta enviada por el servidor
};
typedef msj mensaje; 

class PaqueteDatagrama {
public:
   PaqueteDatagrama(char *, unsigned int , char *, int );
   PaqueteDatagrama(unsigned int);
   ~PaqueteDatagrama();
   char *obtieneDireccion();
   unsigned int obtieneLongitud();
   int obtienePuerto();
   char *obtieneDatos();
   void inicializaPuerto(int);
   void inicializaIp(char *);
   void inicializaDatos(char *);
private:
   char *datos;
   char ip[16];   
   unsigned int longitud;
   int puerto;  
};

#endif
