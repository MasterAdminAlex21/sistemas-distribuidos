#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <arpa/inet.h>

class SocketDatagrama{ 
	public:
		SocketDatagrama(int);
		~SocketDatagrama();
		//Recibe un paquete tipo datagrama proveniente de este socket 
		int recibe(PaqueteDatagrama & p);
		//Envía un paquete tipo datagrama desde este socket
		int envia(PaqueteDatagrama & p);
		void setTimeOut(time_t segundos, suseconds_t microsegundos);
		void unsetTimeOut();
	private:
		struct sockaddr_in direccionLocal; 
		struct sockaddr_in direccionForanea; 
		int s; //ID socket
		struct timeval ura;
		bool timeout;
};

#endif