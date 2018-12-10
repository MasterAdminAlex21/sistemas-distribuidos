#ifndef RESPUESTA_H
#define RESPUESTA_H

#include "Mensaje.h"
#include "SocketDatagrama.h"

class Respuesta{
  public:
		Respuesta(int pl);
		struct Mensaje *getRequest(void);
		void sendReply(struct Mensaje *peticion);
  private:
		SocketDatagrama *socketlocal;
};

#endif