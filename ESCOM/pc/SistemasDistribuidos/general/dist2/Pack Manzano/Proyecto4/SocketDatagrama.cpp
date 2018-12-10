#include "SocketDatagrama.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <netdb.h>
#include <strings.h>
#include <iostream>
#include <errno.h>
#include <stdlib.h>

using namespace std;

SocketDatagrama::SocketDatagrama(int puertoL)
{
   s = socket(AF_INET, SOCK_DGRAM, 0);
   if( s == -1 ){
      //cout << "Error al asociar el socket"<<endl;
      //exit(1);
   }
   bzero((char *)&direccionLocal, sizeof(struct sockaddr_in));
   bzero((char *)&direccionForanea, sizeof(struct sockaddr_in));      

   direccionLocal.sin_family = AF_INET;
   direccionLocal.sin_addr.s_addr = INADDR_ANY;
   direccionLocal.sin_port = htons(puertoL);
   int b = bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));

   if( b == -1 ){
      //cout << "Error al asociar el socket"<<endl;
      //exit(1); 
   }
}

SocketDatagrama::~SocketDatagrama()
{
   close(s);
}

//Recibe un paquete tipo datagrama proveniente de este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p)
{
   int retorno;
   socklen_t clilen; //Ojo no compila si es un tipo int en C
   clilen = sizeof(direccionForanea);
   retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
   p.inicializaPuerto(ntohs(direccionForanea.sin_port));
   p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
   
   return retorno;
}

//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p)
{
   direccionForanea.sin_family = AF_INET;
   direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   direccionForanea.sin_port = htons(p.obtienePuerto());
   sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
  

}
void SocketDatagrama::setTimeout(time_t segundos, suseconds_t microsegundos){
	timeout = true;	
	tiempoFuera.tv_sec = segundos;
	tiempoFuera.tv_usec = microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempoFuera, sizeof(tiempoFuera));	
}
void SocketDatagrama::unsetTimeout(){
	 setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, NULL, 0);
	timeout = false;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p)
{
   int retorno;
   struct timeval tiempo1;
   struct timeval tiempo2;
   struct timeval res;
		
   socklen_t clilen; //Ojo no compila si es un tipo int en C
   clilen = sizeof(direccionForanea);
   gettimeofday(&tiempo1, NULL);
   retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
   if(retorno < 0){
	if (errno == EWOULDBLOCK)
	{
		fprintf(stderr, "Tiempo para recepción transcurrido\n");	
	}	
	else
	fprintf(stderr, "Error en recvfrom\n");
    }
    else{
		gettimeofday(&tiempo2, NULL);
		timersub(&tiempo2,&tiempo1,&res);
		cout << res.tv_sec << " " << res.tv_usec << endl;		
	}	
   p.inicializaPuerto(ntohs(direccionForanea.sin_port));
   p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
   
   return retorno;
}
