#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

using namespace std;

SocketDatagrama::SocketDatagrama(int	puerto){
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));  
}

SocketDatagrama::~SocketDatagrama(){
	close(s);
}

int	SocketDatagrama::recibe(PaqueteDatagrama &p){
	char arreglo[4];
	recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, NULL, NULL);
	memcpy(arreglo, &direccionForanea.sin_addr.s_addr, 4);	
	p.inicializaPuerto(direccionForanea.sin_port);
	p.inicializaIp(arreglo);
	
	/*socklen_t clilen = sizeof(direccionForanea);
	//int num[2];
	char arreglo[4];
	
	recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	memcpy(arreglo, &direccionForanea.sin_addr.s_addr, 4);	
	p.inicializaPuerto(direccionForanea.sin_port);
	p.inicializaIp(arreglo);*/
	
}

int	SocketDatagrama::envia(PaqueteDatagrama &p){
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	//msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
	/*int clilen = sizeof(direccionForanea);
	int res;
	sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, clilen);*/
}









