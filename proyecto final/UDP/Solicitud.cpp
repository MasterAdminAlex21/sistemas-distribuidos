#include "Solicitud.h"
#include "mensaje.h"
#include "respuesta.h"
#include "archivo.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <cstring>
#define TAM_MAX_DATA 4000
#define TAM_ARCHIVO 512

using namespace std;

Solicitud::Solicitud()
{
	socketlocal = new SocketDatagrama(1234);
}
int Solicitud::doOperation(char *IP, int puerto,int rid,int n, char*filedata)
{

    
	//cout << "ip: "<<IP<< " opid: "<<operationId << " rid: " << rid <<endl;
	//cout << "tamano: "<<sizeof(mensaje)<<endl;
	mensaje m;

	memcpy(m.arguments,filedata,TAM_ARCHIVO*sizeof(char));
	m.n = n;
	m.requestId=rid;


	
	char* copy=(char*)malloc(sizeof(mensaje));
	memcpy(copy,&m,sizeof(mensaje));


	PaqueteDatagrama envio((char*)copy,sizeof(mensaje),IP, puerto);

	int r;
	char* ru,*cad;//=(char*)malloc(20*sizeof(char));
	int id;
	int res;

	time_t segundos = 2;
    suseconds_t microsegundos =  5000;

    int enviado;
	//double x, y;
	respuesta* m0;//=(mensaje*)malloc(sizeof(mensaje));

    
    int nEnviado = 0;
    PaqueteDatagrama paquete(sizeof(respuesta));
    m0=(respuesta*)malloc(sizeof(respuesta));
    cout <<"id: "<< m0->requestId << " rid: " << rid <<endl;

	do {

        socketlocal->envia(envio);

	    while(true) {
            r=socketlocal->recibeTimeout(paquete,segundos,microsegundos);
            if(rid == m0->id)
                break;
        }
        if(r != -1)
            break;
        else
            nEnviado++;
    } while (nEnviado < 7);

    if(nEnviado == 7) {
        cout << "Se han agotado el numero posible de intentos" << endl;
        exit(-1);
    }


	return m0->r;
}