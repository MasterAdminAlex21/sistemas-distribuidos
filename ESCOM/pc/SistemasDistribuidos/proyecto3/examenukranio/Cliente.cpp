#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


using namespace std;

int puerto = 0;
int pto_server = 7200;
char *ip_server= "192.168.0.124";

int main(void) 
{
   char msj[50];
   char num[3];
   num[0] = 2;
   num[1] = 4;

   SocketDatagrama cliente(puerto);

   PaqueteDatagrama pk_send2((char*)num, 3 * sizeof(int), ip_server, pto_server);	
   int m= cliente.envia(pk_send2);

   PaqueteDatagrama pk_recv2(3*sizeof(int));
   int n= cliente.recibe(pk_recv2);
   char *ip_serv= pk_recv2.obtieneDireccion();
   char *msj_serv= pk_recv2.obtieneDatos();
   int pto_serv= pk_recv2.obtienePuerto();
   cout << "Mensaje recibido de servidor: " << ip_serv << ":" << pto_serv << endl;
   cout << ">> " << static_cast<int>(msj_serv[0]) << endl;
 
   return 0;
}

