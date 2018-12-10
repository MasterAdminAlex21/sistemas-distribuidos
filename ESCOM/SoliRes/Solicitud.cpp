#include "SocketDatagrama.h"
#include "Solicitud.h"
#include "mensaje.h"
#include <string.h>
#include <cstring>

Solicitud::Solicitud() {
	socketlocal =  SocketDatagrama(0);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{
	
	mensaje.messageType=0;
	strcpy(mensaje.IP, IP); 
	mensaje.puerto=puerto;
	mensaje.operationId=operationId; //Identificador de la operación
	strcpy(mensaje.arguments, arguments); 
	PaqueteDatagrama paq =PaqueteDatagrama(mensaje.arguments, 1000, mensaje.IP,mensaje.puerto);
	
	int n=socketlocal.envia(&paq);
};


