

#ifndef __Solicitud__
#define __Solicitud__

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include "SocketDatagrama.h"

class Solicitud
{
	public:
		Solicitud();
		void doOperation(char *IP, int puerto, int operationId, char *arguments);
	private:
		SocketDatagrama* socketlocal;
};

#endif
