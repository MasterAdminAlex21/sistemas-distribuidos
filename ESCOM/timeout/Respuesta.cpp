#include <string.h>
#include "Respuesta.h"
#include <iostream>
using namespace std;
Respuesta::Respuesta(int pl){
	socketLocal = new SocketDatagrama(pl);
}

struct mensaje Respuesta::getRequest(void){
	struct mensaje resp;
	PaqueteDatagrama pd(sizeof(mensaje));
	socketLocal->recibe(pd);
	memcpy(&resp, pd.obtieneDatos(), sizeof(mensaje));
	memcpy(resp.IP, pd.obtieneDireccion(), sizeof(resp.IP));
	resp.puerto=pd.obtienePuerto();
	return resp;
}

void Respuesta::sendReply(char * respuesta, char* ipCliente, int puertoCliente, int rqID){
	struct mensaje msg;
	msg.messageType = 1;
	msg.requestId = rqID;
	memcpy(msg.IP, ipCliente, sizeof(ipCliente));
	msg.puerto = puertoCliente;
	msg.operationId = 0;
	strcpy(msg.arguments,respuesta);
	PaqueteDatagrama pd((char *)ipCliente,sizeof(mensaje),(char *)&msg, puertoCliente);
	socketLocal->envia(pd);

}
