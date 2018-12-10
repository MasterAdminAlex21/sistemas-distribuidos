#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
using namespace std;

 
SocketDatagrama:: SocketDatagrama(int p){ 
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la direcciòn del cliente*/
   bzero((char *)&direccionLocal, sizeof(direccionLocal));
   direccionLocal.sin_family = AF_INET;
   direccionLocal.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   direccionLocal.sin_port = htons(p);
   int b = bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
 }

 int  SocketDatagrama::recibe(PaqueteDatagrama &p)
 {
   socklen_t len = sizeof( direccionForanea );
   int ret = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr*)&direccionForanea,&len);

   return ret;
 }
 
int  SocketDatagrama::envia(PaqueteDatagrama &p)
 {
   bzero((char *)&direccionForanea, sizeof(direccionForanea));
   direccionForanea.sin_family = AF_INET;
   direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion().c_str());
   direccionForanea.sin_port = htons(p.obtienePuerto());


   return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
   
   
 }

