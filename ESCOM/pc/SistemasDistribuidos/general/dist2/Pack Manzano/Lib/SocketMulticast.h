#ifndef SOCKETMULTICAST_H_
#define SOCKETMULTICAST_H_

#include "PaqueteDatagrama.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <netdb.h>
#include <strings.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <signal.h>

class SocketMulticast{
public:
   SocketMulticast( int); //puerto local no se podrá cambiar para el proceso. Si es cero, lo asigna el sistema operativo
   ~SocketMulticast();
   int recibe( PaqueteDatagrama & p, char *ipE );
   int envia( PaqueteDatagrama & p, unsigned char TTL);
private:
   struct sockaddr_in direccionLocal;
   struct sockaddr_in direccionForanea;
   int s;
};

#endif

