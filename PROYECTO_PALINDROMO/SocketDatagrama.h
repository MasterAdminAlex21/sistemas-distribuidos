#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include "PaqueteDatagrama.h"

class SocketDatagrama{
	public:
		SocketDatagrama(int);
		~SocketDatagrama();
		//Recibe un paquete tipo datagrama proveniente de este socket
		int recibe(PaqueteDatagrama &p);
		int recibeTimeout(PaqueteDatagrama &p,time_t,suseconds_t);	
		//Envía un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama &p);
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s; //ID socket
};

#endif