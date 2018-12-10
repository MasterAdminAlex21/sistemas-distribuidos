#include <iostream>
#include "respuesta.h"

using namespace std;

Respuesta::Respuesta(int pl){
 socketlocal=new SocketDatagrama(pl);
}

struct mensaje* Respuesta::getRequest(){
 PaqueteDatagrama *p1;
 socketlocal->recibe(*p1);
 struct mensaje *men;
 char *args;
 args=p1->obtieneDatos();
 men=(struct mensaje* )args;
 return men;
}

void Respuesta::sendReply(char *respuesta, char *ipcliente,int puertocliente){
 struct mensaje resp;
 resp.messageType=1;
 resp.requestId=0;
 memcpy(resp.IP,ipcliente,16);
 resp.puerto=puertocliente;
 resp.operationId=0;
 memcpy(resp.arguments,respuesta,sizeof(respuesta));
 char aux[4500];
 strcat(aux,(char*)&resp.messageType);
 strcat(aux,(char*)&resp.requestId);
 strcat(aux,resp.IP);
 strcat(aux,(char*)&resp.puerto);
 strcat(aux,(char*)&resp.operationId);
 strcat(aux,resp.arguments);

 PaqueteDatagrama *p;
 p=new PaqueteDatagrama(aux,sizeof(aux),ipcliente,puertocliente);
 socketlocal->envia(*p);
}