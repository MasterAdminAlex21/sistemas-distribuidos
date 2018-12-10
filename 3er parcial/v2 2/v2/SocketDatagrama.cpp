#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

using namespace std;



SocketDatagrama::SocketDatagrama(int port){
	

    
	s = socket( AF_INET,SOCK_DGRAM,0 );
	bzero((char*)&direccionLocal, sizeof(direccionLocal));
			printf("puerto :%x\n",port );
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = inet_addr("10.100.70.252");
	direccionLocal.sin_port = htons( port );
	      	printf("puerto bigendian: %x\n", direccionLocal.sin_port);
	      	printf("puerto %d\n",port );
	      	unsigned char arreglo2[4];
			memcpy(arreglo2,&direccionLocal.sin_addr.s_addr,4);
			printf("direccion local: %d.%d.%d.%d\n",arreglo2[0],arreglo2[1],arreglo2[2],arreglo2[3] );
	int k=bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
			printf("resultado de bind: %d\n", k);

	

}

SocketDatagrama::~SocketDatagrama(){
	close (s);
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
	
	int response=0;
	
	//relleno la direccion del destinatario
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr((char*)p.obtieneDireccion());
		cout<<"Envio a la direccion "<<p.obtieneDireccion()<<endl;
		cout<<"Con el puerto "<<p.obtienePuerto()<<endl;
	//cuando se utiliza por numero del puerto el 0, el sistema se encarga de asignarle uno
	direccionForanea.sin_port =htons(p.obtienePuerto());
	unsigned int clilen = sizeof(direccionForanea);
	response=sendto(s,p.obtieneDatos(), p.obtieneLongitud(),0,(struct sockaddr *)&direccionForanea,clilen);
	
	return response;
}



int SocketDatagrama::recibe(PaqueteDatagrama &p){
	int response=0;
	unsigned int clilen = sizeof(direccionForanea);
	response=recvfrom(s,p.obtieneDatos(), p.obtieneLongitud(),0,(struct sockaddr *)&direccionForanea,&clilen);


	//ahora relleno info
	cout<<"Puerto del cliente "<<ntohs(direccionForanea.sin_port)<<endl;
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	unsigned char arreglo2[4];
	char arreglo[16];
	memcpy(arreglo2,&direccionForanea.sin_addr.s_addr,4);
	sprintf(arreglo,"%d.%d.%d.%d\n",arreglo2[0],arreglo2[1],arreglo2[2],arreglo2[3] );
	puts(arreglo);
	p.inicializaIp((unsigned char*)arreglo);
	//puts(p.obtieneDireccion());


	return response;
}



int SocketDatagrama::recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos){
	struct timeval timeout;
	timeout.tv_sec = segundos;
	timeout.tv_usec = microsegundos;
	setsockopt(s,SOL_SOCKET,SO_RCVTIMEO, (char * ) &timeout, sizeof(timeout));

	int response=0;
	unsigned int clilen = sizeof(direccionForanea);
	response=recvfrom(s,p.obtieneDatos(), p.obtieneLongitud(),0,(struct sockaddr *)&direccionForanea,&clilen);

	if(response<0){
		if(errno == EWOULDBLOCK)
			fprintf(stderr, "Tiempo para la recepcion ha transcurrido\n");
		else
			fprintf(stderr, "Error en el recvfrom\n");
		return 0;
	}
	else{
		//ahora relleno info
		cout<<"Puerto del cliente "<<ntohs(direccionForanea.sin_port)<<endl;
		p.inicializaPuerto(ntohs(direccionForanea.sin_port));
		unsigned char arreglo2[4];
		char arreglo[16];
		memcpy(arreglo2,&direccionForanea.sin_addr.s_addr,4);
		sprintf(arreglo,"%d.%d.%d.%d\n",arreglo2[0],arreglo2[1],arreglo2[2],arreglo2[3] );
		puts(arreglo);
		p.inicializaIp((unsigned char*)arreglo);
		//puts(p.obtieneDireccion());


		return response;
	}
}

int SocketDatagrama::enviaTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos){
	struct timeval timeout;
	timeout.tv_sec = segundos;
	timeout.tv_usec = microsegundos;
	setsockopt(s,SOL_SOCKET,SO_RCVTIMEO, (char * ) &timeout, sizeof(timeout));

	int response=0;
	//relleno la direccion del destinatario
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr((char*)p.obtieneDireccion());
	cout<<"Envio a la direccion "<<p.obtieneDireccion()<<endl;
	cout<<"Con el puerto "<<p.obtienePuerto()<<endl;

	direccionForanea.sin_port =htons(p.obtienePuerto());
	unsigned int clilen = sizeof(direccionForanea);
	response=sendto(s,p.obtieneDatos(), p.obtieneLongitud(),0,(struct sockaddr *)&direccionForanea,clilen);
	

	if(response<0){
		if(errno == EWOULDBLOCK)
			fprintf(stderr, "Tiempo para la recepcion ha transcurrido\n");
		else
			fprintf(stderr, "Error en el sendto\n");
		return 0;
	}
	else{
		return response;
	}


	
}
