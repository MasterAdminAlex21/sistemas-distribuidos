#include "SocketDatagrama.h"
#include "mensaje.h"
#ifndef RESPUESTA_H_
#define RESPUESTA_H_
class Respuesta
{
	public:
		Respuesta(int pl);
		mensaje* getRequest(void);
		void sendReply(char *respuesta, char *ipCliente, int puertoCliente,int);
	private:
		SocketDatagrama *socketlocal;
};
#endif