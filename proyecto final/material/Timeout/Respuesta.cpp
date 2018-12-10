#include <iostream>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.h"

using namespace std;

Respuesta::Respuesta(int pl){
	socketlocal = new SocketDatagrama(pl);
}

struct Mensaje *Respuesta::getRequest(){        
    struct Mensaje *menr = (struct Mensaje *) malloc(sizeof(struct Mensaje));
	PaqueteDatagrama p1(sizeof(struct Mensaje));
	socketlocal->recibe(p1);
	memcpy(menr,(struct Mensaje *)p1.obtieneDatos(),p1.obtieneLongitud());
	memcpy(menr->IP,p1.obtieneDireccion(),sizeof(char)*16);
	menr->puerto = p1.obtienePuerto();
	return menr;
}

void Respuesta::sendReply(struct Mensaje *peticion){
        PaqueteDatagrama p2((char*)peticion,sizeof(struct Mensaje),peticion->IP,peticion->puerto);
        socketlocal->envia(p2);
}