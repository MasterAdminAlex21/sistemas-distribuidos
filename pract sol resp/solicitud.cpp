#include <iostream>
#include <string.h>
#include "solicitud.h"
#include "mensaje.h"

using namespace std;

Solicitud::Solicitud(){
  socketlocal= new SocketDatagrama(0);
}

char * Solicitud::doOperation(char *IP, int puerto, int operacionId,char *arguments){
 //usar paquetesdatagramas para esto
 //aqui se llena el mensaje
 struct mensaje m;
 m.messageType=0;
 m.requestId=0;
 memcpy(m.IP,IP,16);
 m.puerto=puerto;
 m.operationId=operacionId;
 memcpy(m.arguments,arguments,sizeof(arguments));
 //se termina de llenar el mensaje
 char aux[4500];
 strcat(aux,(char*)&m.messageType);
 strcat(aux,(char*)&m.requestId);
 strcat(aux,m.IP);
 strcat(aux,(char*)&m.puerto);
 strcat(aux,(char*)&m.operationId);
 strcat(aux,m.arguments);
 //
 PaqueteDatagrama *p;
 p=new PaqueteDatagrama(aux,strlen(aux),IP,puerto);
 socketlocal->envia(*p);
 socketlocal->recibe(*p);
 return p->obtieneDatos();
}