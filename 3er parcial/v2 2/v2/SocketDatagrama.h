#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include "PaqueteDatagrama.h"
using namespace std;


#ifndef SOCKETDATAGRAMA_H_
#define SOCKETEDATAGRAMA_H_
	
class SocketDatagrama
{
private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s; //ID socket


public:
	SocketDatagrama(int port);
	~SocketDatagrama();
	int recibe(PaqueteDatagrama &p);
	int envia(PaqueteDatagrama &p);
	int recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);
	int enviaTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);
};



 #endif