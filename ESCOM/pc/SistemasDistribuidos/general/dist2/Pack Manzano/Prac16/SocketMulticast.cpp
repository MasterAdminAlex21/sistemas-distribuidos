#include "SocketMulticast.h"
using namespace std;

SocketMulticast::SocketMulticast(int puertoL)
{ 
	s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if( s < 0 ){
		cout << "Error asociando el multicast"<<endl;
		exit(0);	
	}
   bzero((char *)&direccionLocal, sizeof(struct sockaddr_in));
   bzero((char *)&direccionForanea, sizeof(struct sockaddr_in));      

   direccionLocal.sin_family = AF_INET;
   direccionLocal.sin_addr.s_addr = INADDR_ANY;
   direccionLocal.sin_port = htons(puertoL);
   int b = bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
   if( b < 0 ){
   		perror("Bind");
   		exit(0);
   }
}

SocketMulticast::~SocketMulticast(){
   close(s);
}

//Recibe un paquete tipo datagrama proveniente de este socket
int SocketMulticast::recibe(PaqueteDatagrama & p, char* ipE){
	ip_mreq multicast;
	multicast.imr_multiaddr.s_addr = inet_addr( ipE );
	multicast.imr_interface.s_addr = htonl( INADDR_ANY ); 
   	int opc = setsockopt( s, IPPROTO_IP, IP_ADD_MEMBERSHIP, &multicast, sizeof(multicast) );
   	if( opc < 0){
   		perror("error");
		cout << "Error recibiendo multicast"<<endl;
		exit(0);
	}

	socklen_t clilen; //Ojo no compila si es un tipo int en C
	clilen = sizeof(direccionForanea);
	int retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));

	if( setsockopt( s, IPPROTO_IP, IP_DROP_MEMBERSHIP, &multicast, sizeof(multicast) ) < 0){
		cout << "Error cerrando el multicast"<<endl;
		exit(0);
	}

	return retorno;
}

//Envía un paquete tipo datagrama desde este socket 
int SocketMulticast::envia(PaqueteDatagrama &p, unsigned char TTL){
	if( setsockopt( s, IPPROTO_IP, IP_MULTICAST_TTL, (void *) &TTL, sizeof(TTL) ) < 0){
		cout << "Error enviando multicast"<<endl;
		exit(0);
	}

   direccionForanea.sin_family = AF_INET;
   direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   direccionForanea.sin_port = htons(p.obtienePuerto());
   return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}
