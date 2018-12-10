#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <new>
#include <iostream>
#include <errno.h>
#include <arpa/inet.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
using namespace std;

SocketDatagrama::SocketDatagrama(int puerto){
	s  = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

unsigned int SocketDatagrama::recibe(PaqueteDatagrama & p){
	socklen_t plen;
	plen = sizeof(direccionForanea);
	unsigned int res = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &plen);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	return res;
}

unsigned int SocketDatagrama::envia(PaqueteDatagrama & p){
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr*) &direccionForanea, sizeof(direccionForanea));
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p, time_t segundos, time_t microsegundos){
	timeout.tv_sec = segundos;
	timeout.tv_usec = microsegundos;
	setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(timeout));
	socklen_t plen;
	plen = sizeof(direccionForanea);
	int res = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &plen);
	if(res<0){
		if(errno == EWOULDBLOCK){
			printf("Tiempo agotado  ");
			return -1;
		}else{
			printf("Error en recibir\n");
		}
	}else{
		p.inicializaPuerto(ntohs(direccionForanea.sin_port));
		p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	}
	return 1;
}
