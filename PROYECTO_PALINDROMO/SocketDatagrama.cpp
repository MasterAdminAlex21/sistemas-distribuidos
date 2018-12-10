#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <iostream>
#include <errno.h>
#include <sys/time.h>

using namespace std;
struct timeval timeout;
//timeout.tv_sec=2;
//timeout.tv_usec=500000;

SocketDatagrama::SocketDatagrama(int puerto){
	s = socket(AF_INET,SOCK_DGRAM,0);
	bzero((char *)&direccionLocal,sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama(){
	close (s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
	unsigned int clilen;
	clilen = sizeof(direccionForanea);
	int rec = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	return rec;	
}

int SocketDatagrama::envia(PaqueteDatagrama &p){	
  direccionForanea.sin_family = AF_INET;
  direccionForanea.sin_port = htons(p.obtienePuerto());
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}
int SocketDatagrama::recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos)
{
	timeout.tv_sec=segundos;
	timeout.tv_usec=microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
	unsigned int clilen;
	clilen = sizeof(direccionForanea);
	int rec=recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	//cout <<" saaaaaalidaaaaa: " << rec <<endl;
	if(rec<0){
		if(errno==EWOULDBLOCK){
			cout <<"Tiempo se agoto." <<endl;
			return -1;
		}
		else{
			cout <<"Error" <<endl;
			return -2;
		}
	}
	return 0;
}