#ifndef SOCKETDATAGRAMA
#define SOCKETDATAGRAMA

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>

#include "PaqueteDatagrama.h"

class SocketDatagrama{

public:
	SocketDatagrama(int);	
	~SocketDatagrama();
	int recibe(PaqueteDatagrama &p);
	int envia(PaqueteDatagrama &p);
private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s;
};

#endif
