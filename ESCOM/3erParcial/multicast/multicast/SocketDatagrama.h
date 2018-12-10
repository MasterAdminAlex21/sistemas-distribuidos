#ifndef SOCKETDATAGRAMA
#define SOCKETDATAGRAMA

#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>


#include "PaqueteDatagrama.h"

class SocketDatagrama{

public:
	SocketDatagrama(int);	
	~SocketDatagrama();
	void setTimeout(time_t segundos, suseconds_t microsegundos);
   	void unsetTimeout( );
   	struct timeval getTimeout();
   	int recibeTimeout( PaqueteDatagrama &p ); 
	int recibe(PaqueteDatagrama &p);
	int envia(PaqueteDatagrama &p);
	void setBroadcast();
	void unsetBroadcast();
private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s;
	struct timeval tiempo;
	bool timeout;

};

#endif
