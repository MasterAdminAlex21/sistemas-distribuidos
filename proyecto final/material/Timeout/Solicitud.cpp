#include <iostream>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Solicitud.h"
#include "Mensaje.h"
#include <sys/time.h>

using namespace std;

Solicitud::Solicitud(int port){
	socketlocal = new SocketDatagrama(port);  	
}

char* Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments,int numSol){
    struct Mensaje men;
    men.messageType=0;
    men.requestId=numSol;
    memcpy(men.IP,IP,sizeof(char)*16);//men.IP=IP;  
    men.puerto=puerto;
    men.operationId=operationId;
    memcpy(men.arguments, arguments,sizeof(char)*TAM_MAX_DATA);
	PaqueteDatagrama p1((char *)&men,sizeof(men),IP,puerto);
    time_t segundos = 2;
    suseconds_t microsegundos =  5000;
    int enviado;
    int nEnviado = 0;
	do {
        socketlocal->envia(p1);
	    while(true) {
            enviado = socketlocal->recibeTimeout(p1,segundos,microsegundos);
            if((unsigned int)numSol == ((struct Mensaje *)p1.obtieneDatos())->requestId)
                break;
        }
        if(enviado != -1)
            break;
        else
            nEnviado++;
    } while (nEnviado < 7);
    if(nEnviado == 7) {
        cout << "Se han agotado el numero posible de intentos" << endl;
        exit(-1);
    }
	return p1.obtieneDatos();
}
