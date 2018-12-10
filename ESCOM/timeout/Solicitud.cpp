#include <netinet/in.h>
#include <string.h>
#include "Solicitud.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <stdio.h>
using namespace std;
char res[TAM_MAX_DATA];

Solicitud::Solicitud(){
	socketLocal = new SocketDatagrama(0);
}

char* Solicitud::doOperation(char * IP, int puerto, int operationId, char * arguments, int rqID){
	struct mensaje msg;
	msg.messageType = 0;
	msg.requestId = rqID;
	memcpy(msg.IP, IP, sizeof(char*));
	msg.puerto = puerto;
	msg.operationId = operationId;
	strcpy(msg.arguments,arguments);
	PaqueteDatagrama pd((char *)IP,sizeof(mensaje),(char *)&msg, puerto);
	PaqueteDatagrama pr(sizeof(mensaje));
	int r = -1;
	int i = 0;
	while(r==-1 && i<INTENTOS ){
		socketLocal->envia(pd);
		r=socketLocal->recibeTimeout(pr,SEGUNDOS,uSEGUNDOS);
		i++;
	}
	if(r==-1 && i==7){
		printf("El servior no está disponible, intente más tarde\n");
	}
	struct mensaje msgRec;
	memcpy(&msgRec, pr.obtieneDatos(), sizeof(mensaje));
	printf("\t\t\t\t\tSrequestId: %d\n", rqID);
	printf("\t\t\t\t\tSRreqID: %d\n", msgRec.requestId);
	printf("\t\t\t\t\tSopID: %d\n", operationId);
	if(rqID == msgRec.requestId){
		memcpy(res,msgRec.arguments,sizeof(msgRec.arguments));
	}
	else{
		printf("Mensaje previamente recibido\n");
		return "-1";
	}
	return res;
}
