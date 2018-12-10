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
	cout<<"Bytes enviados: "<<sockt->envia(packet)<<endl;
}


struct mensaje * Respuesta::getRequest(void){
	PaqueteDatagrama packet(sizeof(mensaje));
	cout<<"Longitud del paquete: "<<packet.obtieneLongitud()<<endl;
	cout<<"Bytes recibidos: "<<sockt->recibe(packet)<<endl;
	mensaje *prueba=(mensaje*)malloc(sizeof(mensaje));

	return (mensaje*)packet.obtieneDatos();
}

