#ifndef SOCKMULTI
#define SOCKMULTI

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

class SocketMulticast {
	public:
		SocketMulticast(int);	
		~SocketMulticast();
		void setTimeout(time_t segundos, suseconds_t microsegundos);
	   	void unsetTimeout( );
	   	struct timeval getTimeout();
	   	int recibeTimeout( PaqueteDatagrama &p ); 
		int recibe(PaqueteDatagrama &p, char*);
		int envia(PaqueteDatagrama &p, unsigned char ttl);
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s;
		struct timeval tiempo;
		bool timeout;
};

#endif
