#include <string.h>
#include "PaqueteDatagrama.h"

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *datosE, unsigned int longitudE, char *ipE, int puertoE)
{
   longitud = longitudE;
   datos = new char[longitudE + 1];
   memcpy(datos, datosE, longitudE);   
   strcpy(ip, ipE);
   puerto = puertoE;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitudE)
{
   longitud = longitudE;
   datos = new char[longitudE + 1];
   strcpy(datos, "");   
   strcpy(ip, "");
}

PaqueteDatagrama::~PaqueteDatagrama()
{
   delete []datos;
}

char * PaqueteDatagrama::obtieneDireccion()
{
   return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
   return longitud;
}

int PaqueteDatagrama::obtienePuerto()
{
   return puerto;
}

char * PaqueteDatagrama::obtieneDatos()
{
   return datos;
}

void PaqueteDatagrama::inicializaPuerto(int pu)
{
   puerto = pu;
   return;
}

void PaqueteDatagrama::inicializaIp(char *IP)
{
   strcpy(ip, IP);
   return;
}

void PaqueteDatagrama::inicializaDatos(char *DATOS)
{
   memcpy(datos, DATOS, longitud);
}

