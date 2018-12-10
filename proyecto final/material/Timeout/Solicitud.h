#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "SocketDatagrama.h"

class Solicitud{
	public:
		Solicitud(int port);
		char* doOperation(char *IP, int puerto, int operationId, char *arguments,int numSol);
	private:
		SocketDatagrama *socketlocal;
};

#endif