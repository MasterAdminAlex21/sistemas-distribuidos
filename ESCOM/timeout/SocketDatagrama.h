#ifndef SOCKETDATAGRAMA_H
#define SOCKETDATAGRAMA_H
#include <netinet/in.h>
#include <sys/time.h>
class SocketDatagrama{
public:
	SocketDatagrama(int port);
	//~SocketDatagrama();
	//Recibe un paquete tipo datagrama proveniente de este socket
	unsigned int recibe(PaqueteDatagrama & p);
	//Envía un paquete tipo datagrama desde este socket
	unsigned int envia(PaqueteDatagrama & p);
	int recibeTimeout(PaqueteDatagrama & p, time_t segundos, time_t microsegundos);
private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s; //ID socket
	struct timeval timeout;
};
#endif
