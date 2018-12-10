#include "SocketDatagrama.h"
#include <errno.h>

SocketDatagrama::SocketDatagrama(int puerto) {
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionLocal.sin_port = htons(puerto);
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama() {
	close(s);
}	

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
	unsigned int clilen = sizeof(direccionForanea);
	int res = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0,(struct sockaddr *)&direccionForanea, &clilen);
	p.inicializaPuerto(htons(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	printf("%s: %d \n",p.obtieneDireccion(),p.obtienePuerto());
	return res;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p, time_t segundos, suseconds_t microsegundos) {
	unsigned int clilen = sizeof(direccionForanea);
	timeout.tv_sec = segundos;
	timeout.tv_usec = microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
	int res = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0,(struct sockaddr *)&direccionForanea, &clilen);
	if (res < 0) {
		if (errno == EWOULDBLOCK){
			fprintf(stderr, "Tiempo para recepción transcurrido\n");
			return -1;
		}
		else {
			fprintf(stderr, "Error en recvfrom\n");
			return res;
		}
	}
	p.inicializaPuerto(htons(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	printf("%s: %d \n",p.obtieneDireccion(),p.obtienePuerto());
	return res;
}

int SocketDatagrama::envia(PaqueteDatagrama &p) {
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}