#include "Respuesta.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
#define TAM_MAX_DATA 4000

using namespace std;

Respuesta::Respuesta(int pl){

	socketlocal = new SocketDatagrama(pl);
}

mensaje* Respuesta::getRequest(void){

	PaqueteDatagrama paquete(sizeof(mensaje));
    int r=socketlocal->recibe(paquete);
 
  	
	mensaje* m=(mensaje*)malloc(sizeof(mensaje));
	memcpy(m,paquete.obtieneDatos(),sizeof(mensaje));
	
	memcpy(m->IP,paquete.obtieneDireccion(),16*sizeof(char));

	m->puerto=paquete.obtienePuerto();
	return m;
}
void Respuesta::sendReply(char * respuesta, char *ipCliente, int puertoCliente,int rid)
{


    
    // char* x=(char*)malloc(sizeof(respuesta));
     //memcpy(x,&respuesta,sizeof(mensaje));
	/*mensaje m;
    

	memcpy(m.arguments,respuesta,TAM_MAX_DATA*sizeof(char));
	m.requestId=rid;

	char* x=(char*)malloc(sizeof(mensaje));
	memcpy(x,&m,sizeof(mensaje));
    */
	PaqueteDatagrama envio(respuesta,2*sizeof(int),ipCliente, puertoCliente);
	socketlocal->envia(envio);
}

