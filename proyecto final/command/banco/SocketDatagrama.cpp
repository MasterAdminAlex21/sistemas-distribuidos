#include "SocketDatagrama.h"

SocketDatagrama::SocketDatagrama(int puerto){
	s = socket(AF_INET, SOCK_DGRAM, 0);
	/* rellena la dirección del servidor */
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(puerto); // si es 0, el puerto será asignado por el Sistema Operativo
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));

}

SocketDatagrama::~SocketDatagrama(){
	close(s);
}

int SocketDatagrama::envia(PaqueteDatagrama &p) {
	int enviados = 0;
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    enviados = sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea)); 
 
    return enviados;
}

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
	int recibidos = 0;
    char datos[p.obtieneLongitud()];
    char aux[INET_ADDRSTRLEN];
    socklen_t clilen = sizeof(direccionForanea);
    recibidos = recvfrom(s, datos, p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &clilen);
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), aux, INET_ADDRSTRLEN);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaIp(aux);
    p.inicializaDatos(datos);

    return recibidos;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama &p,time_t segundos,suseconds_t microsegundos){
    tiempo.tv_sec=segundos;
    tiempo.tv_usec=microsegundos;
    char datos[p.obtieneLongitud()];
    socklen_t clilen=sizeof(direccionForanea);
    char aux[INET_ADDRSTRLEN];

    setsockopt(s,SOL_SOCKET,SO_RCVTIMEO,(char*)&tiempo,sizeof(tiempo));

    int n;
    n=recvfrom(s, datos, p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, &clilen);
    if(n<0){
        if(errno==EWOULDBLOCK){
            fprintf(stderr," Tiempo para recepcion transcurrido\n");
        }
        else{
            fprintf(stderr," Error en recvfrom\n");
        }
        return 0;
    }
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), aux, INET_ADDRSTRLEN);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaIp(aux);
    p.inicializaDatos(datos);
    return n;
}
