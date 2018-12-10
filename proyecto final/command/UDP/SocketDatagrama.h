#ifndef _SOCKETDATAGRAMA_H_
#define _SOCKETDATAGRAMA_H_

#include <sys/time.h>
#include "PaqueteDatagrama.h"

class SocketDatagrama {
	public:
		SocketDatagrama(int);
		~SocketDatagrama();				
		int recibe(PaqueteDatagrama &p);	//Recibe un paquete tipo datagrama proveniente de este socket
		int recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);
		int envia(PaqueteDatagrama &p);		//Envía un paquete tipo datagrama desde este socket
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s; //ID socket
		struct timeval timeout;
};

#endif