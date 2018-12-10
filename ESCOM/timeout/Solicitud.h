#ifndef SOLICITUD_H
#define SOLICITUD_H
#include "mensaje.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#define INTENTOS 7
#define SEGUNDOS 1
#define uSEGUNDOS 100
//2.0001 segundos
class Solicitud
{
public:
	Solicitud();
	char * doOperation(char * IP, int puerto, int operationId, char * arguments, int rqID);
private:
	SocketDatagrama *socketLocal;
};
#endif
