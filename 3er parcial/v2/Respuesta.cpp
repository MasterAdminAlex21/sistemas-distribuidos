#include <stdio.h>
#include <iostream>
#include <string>
#include "PaqueteDatagrama.h"
#include "Respuesta.h"


using namespace std;

//void sendReply(char *respuesta, char *ipCliente, int puertoCliente)

Respuesta::Respuesta(int pl){
	sockt=new SocketDatagrama(pl);

}

void Respuesta::sendReply(char *respuesta, unsigned char *ipCliente, int puertoCliente, int Longitud){
	PaqueteDatagrama packet(sizeof(mensaje));

	
	packet.inicializaPuerto(puertoCliente);
	packet.inicializaIp(ipCliente);
	packet.inicilizaLongitud(Longitud);
	packet.inicializaDatos(respuesta);
	cout<<"Longitud del paquete: "<<packet.obtieneLongitud()<<endl;
	cout<<"Bytes enviados: ";

	int i=0;
	do{	
		if(sockt->enviaTimeout(packet,2,500000)>0){
			break;
		}

		i++;
	}while(i<6);
	if(i==6)
		cout<<"El servidor no esta disponible, intente mas tarde"<<endl;

}


struct mensaje * Respuesta::getRequest(void){
	PaqueteDatagrama packet(sizeof(mensaje));
	sockt->recibe(packet);
	cout<<"Longitud del paquete: "<<packet.obtieneLongitud()<<endl;
	
	


	mensaje *prueba=(mensaje*)malloc(sizeof(mensaje));

	return (mensaje*)packet.obtieneDatos();
}

