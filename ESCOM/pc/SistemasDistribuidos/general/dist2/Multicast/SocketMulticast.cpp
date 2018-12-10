#include "SocketMulticast.h"

SocketMulticast :: SocketMulticast(int puerto){
	timeout = false;
	s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
   	direccionLocal.sin_family = AF_INET;
   	direccionLocal.sin_addr.s_addr = INADDR_ANY;
   	direccionLocal.sin_port = htons(puerto);
   	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketMulticast :: ~SocketMulticast(){
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	close(s);
}

void SocketMulticast :: unsetTimeout(){
	timeout = false;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, 0, 0);
}

void SocketMulticast :: setTimeout(time_t segundos, suseconds_t microsegundos){
	tiempo.tv_sec = segundos;
	tiempo.tv_usec = microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempo, sizeof(tiempo));
	timeout = true;
}

int SocketMulticast :: recibeTimeout(PaqueteDatagrama &p){
	struct timeval t1, t2, tr;

	int retorno;
	socklen_t clilen;
	clilen = sizeof(direccionForanea);
	gettimeofday(&t1, NULL);
	retorno = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	gettimeofday(&t2, NULL);
	if(retorno < 0){
		std :: cout << "Tiempo Excedido" << std :: endl;
		if(errno == EWOULDBLOCK)
			retorno = retorno;
		else
			std :: cout << "Error en recvfrom" << std :: endl;
	}
	if(retorno > 0){
		unsetTimeout();
		timersub(&t2, &t1, &tr);
		std :: cout << "Tiempo de recepcion" << std :: endl;
		std :: cout << "Segundos: " << tr.tv_sec << std :: endl;
		std :: cout << "Microsegundos: " << tr.tv_usec << std :: endl;

	}
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	inet_ntop(AF_INET, &(direccionForanea.sin_addr), p.obtieneDireccion(), INET_ADDRSTRLEN);
	return retorno;
}

int SocketMulticast :: recibe(PaqueteDatagrama &p, char *ipE) {
	struct ip_mreq multicast;
	multicast.imr_multiaddr.s_addr = inet_addr(ipE);
	multicast.imr_interface.s_addr = htonl(INADDR_ANY);
	
	setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *) &multicast, sizeof(multicast));

	socklen_t clilen =  sizeof(direccionForanea);
	int retorno = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	inet_ntop(AF_INET, &(direccionForanea.sin_addr), p.obtieneDireccion(), INET_ADDRSTRLEN);
	
	return retorno; 
}

int SocketMulticast :: envia(PaqueteDatagrama &p, unsigned char TTL) {
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL));

	socklen_t clilen =  sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
   	direccionForanea.sin_family = AF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons(p.obtienePuerto());
	int retorno = sendto(s,(char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
	
	return retorno; 
}
