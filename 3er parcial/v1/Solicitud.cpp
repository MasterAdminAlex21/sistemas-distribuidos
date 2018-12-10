#include <stdio.h>
#include <iostream>
#include <string>
#include "PaqueteDatagrama.h"
#include "Solicitud.h"
#include "mensaje.h"

using namespace std;


Solicitud::Solicitud(){
	sockt=new SocketDatagrama(7777);
}

char* Solicitud::doOperation(unsigned char *IP, int puerto, int operationId, char* argumentos){
	PaqueteDatagrama packet(argumentos,sizeof(mensaje),IP,puerto);	
	cout<<"Longitud del paquete: "<<packet.obtieneLongitud()<<endl;
	cout<<"Bytes enviados: "<<sockt->envia(packet)<<endl;


	//cout<<"Bytes recibidos: "<<sockt->recibe(packet)<<endl;
	int i=0;
	do{	
		if(sockt->recibeTimeout(packet,2,500000)>0){
			break;
		}
		i++;
	}while(i<6);
	if(i>6)
		cout<<"El servidor no esta disponible, intente mas tarde";
	

	return packet.obtieneDatos();
	
}