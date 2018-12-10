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
	//double x, y;
	respuesta* m0;//=(mensaje*)malloc(sizeof(mensaje));

	for(int i=0;i<7;i++){
 		
	    socketlocal->envia(envio);
		PaqueteDatagrama paquete(sizeof(respuesta));
		r=socketlocal->recibeTimeout(paquete,1,0);		
		ru=(char*)malloc(sizeof(int));
		m0=(respuesta*)malloc(sizeof(respuesta));

		if(r==0){

			memcpy(m0,paquete.obtieneDatos(),2*sizeof(int));
			cout <<"id:" << m0->id <<" R: "<<m0->r <<endl;
            
			/*if(m0->id==rid)
				//memcpy(res,&m0->r,sizeof(int));
			else
				continue;*/
		  break;
		}
	   
	}
	if(r==-1){
		cout <<"No se ha obtenido respuesta del servidor." <<endl;
		return NULL;
	}
	return m0->r;
}