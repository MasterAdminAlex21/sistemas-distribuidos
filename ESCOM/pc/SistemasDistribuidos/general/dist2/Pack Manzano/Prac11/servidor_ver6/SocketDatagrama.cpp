#include "SocketDatagrama.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <netdb.h>
#include <strings.h>
#include <iostream>
#include <errno.h>

using namespace std;

SocketDatagrama::SocketDatagrama(int puertoL)
{
   s = socket(AF_INET, SOCK_DGRAM, 0);
   bzero((char *)&direccionLocal, sizeof(struct sockaddr_in));
   bzero((char *)&direccionForanea, sizeof(struct sockaddr_in));      

   direccionLocal.sin_family = AF_INET;
   direccionLocal.sin_addr.s_addr = INADDR_ANY;
   direccionLocal.sin_port = htons(puertoL);
   bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal)); 
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
   //struct timeval tiempofuera;
   //tiempofuera.tv_sec = 0;
   //tiempofuera.tv_usec = 500000;

   clilen = sizeof(direccionForanea);
   //setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &tiempofuera, sizeof(tiempofuera));
//   while(1){
   retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
   //if(retorno == -1)
      //return retorno; // No llegó el mensaje en el tiempo requerido
//         break;
//      cout << "Reenviando paquete UDP \n";
//   }
   p.inicializaPuerto(ntohs(direccionForanea.sin_port));
   p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
   
   return retorno;
}

//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p)
{
   int retorno;

   direccionForanea.sin_family = AF_INET;
   direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   direccionForanea.sin_port = htons(p.obtienePuerto());
   retorno = sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
   
   return retorno;
}
