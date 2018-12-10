#include "SocketDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <arpa/inet.h>
#include "stdc++.h"
using namespace std;
SocketDatagrama :: SocketDatagrama(int puerto){
	s = socket(AF_INET, SOCK_DGRAM, 0);
	/*rellenar la dirección local*/ 
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
   	direccionLocal.sin_family = AF_INET;
   	direccionLocal.sin_addr.s_addr = INADDR_ANY;
   	direccionLocal.sin_port = htons(puerto);
   	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama :: ~SocketDatagrama(){
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
}

int SocketDatagrama::envia(PaqueteDatagrama & paquete){
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;	
   	direccionForanea.sin_addr.s_addr = inet_addr(paquete.obtieneDireccion());
   	direccionForanea.sin_port = htons(paquete.obtienePuerto());
   //	cout << "ENVIO A: "<< paquete.obtieneDatos() << " "<< paquete.obtienePuerto() <<" "<<paquete.obtieneDireccion() << endl;
	return sendto(s, paquete.obtieneDatos(), strlen(paquete.obtieneDatos()), 0 ,(struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

int SocketDatagrama::recibe(PaqueteDatagrama & paquete){
	char K[1024];
	int addr_len = sizeof(struct sockaddr);
	int n = recvfrom(s, K, 1024, 0, (struct sockaddr *)&direccionForanea,(unsigned int *) &addr_len);
	if (n < 0) {
 		if (errno == EWOULDBLOCK)
 			fprintf(stderr, " Tiempo para recepción transcurrido\n");
 		else
 			fprintf(stderr, " Error en recvfrom\n");
	}
	paquete.inicializaDatos(K);
	paquete.inicializaPuerto(ntohs(direccionForanea.sin_port));
	paquete.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	return 1;
}
void SocketDatagrama::unsetTimeOut(){
	timeout = false;
	ura.tv_sec = 0;
	ura.tv_usec = 0;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&ura, sizeof(ura));
}
void SocketDatagrama::setTimeOut(time_t segundos, suseconds_t microsegundos){
	timeout = true;
	ura.tv_sec = segundos;
	ura.tv_usec = microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&ura, sizeof(ura));
}