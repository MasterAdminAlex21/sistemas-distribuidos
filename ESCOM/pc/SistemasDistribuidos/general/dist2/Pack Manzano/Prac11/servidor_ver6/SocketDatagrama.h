#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

#include "PaqueteDatagrama.h"
#include <sys/socket.h>
#include <netinet/in.h>

class SocketDatagrama{
public:
   SocketDatagrama(int); //puerto local no se podrá cambiar para el proceso. Si es cero, lo asigna el sistema operativo
   ~SocketDatagrama();
   //Recibe un paquete tipo datagrama proveniente de este socket
   int recibe(PaqueteDatagrama & p);
   //Envía un paquete tipo datagrama desde este socket
   int envia(PaqueteDatagrama & p);
private:   
   struct sockaddr_in direccionLocal;
   struct sockaddr_in direccionForanea;
   int s; //ID socket
};

#endif

