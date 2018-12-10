#include "SocketDatagrama.h"

SocketDatagrama :: SocketDatagrama(int puerto){
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
   	direccionLocal.sin_family = AF_INET;
   	direccionLocal.sin_addr.s_addr = INADDR_ANY;
   	direccionLocal.sin_port = htons(puerto);
   	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

SocketDatagrama :: ~SocketDatagrama(){
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
	socklen_t clilen =  sizeof(direccionForanea);
	int r = recvfrom(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	inet_ntop(AF_INET, &(direccionForanea.sin_addr), p.obtieneDireccion(), INET_ADDRSTRLEN);
	std :: cout << "\n"<< p.obtieneDireccion() << " - "<< p.obtienePuerto() << "   dice, buscar palabra: ";
	return r; 
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
	socklen_t clilen =  sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
   	direccionForanea.sin_family = AF_INET;
   	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   	direccionForanea.sin_port = htons(p.obtienePuerto());
	int r = sendto(s,(char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
	//std :: cout << "Direccion IP del paquete a enviar: " << p.obtieneDireccion() << std :: endl;
	//std :: cout << "Puerto del paquete enviado: " << p.obtienePuerto() << std :: endl;
	return r;
}
