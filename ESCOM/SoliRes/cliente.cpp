#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include "Solicitud.h"

int puerto = 7200;

int main(int argc, char *argv[])
{
	Solicitud sol=  Solicitud();
   if(argc != 2){
		printf("Forma de uso: %s direccion ip\n", argv[0]);
      exit(-1);
	}
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
   
   char arreglo[4];
   //char arregloS[4];
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   //msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   msg_to_server_addr.sin_port = htons(puerto);
   
   //memcpy(arreglo, &msg_to_server_addr.sin_addr.s_addr, 4);
   //printf("contenido de msg_to_server_addr.sin_addr.s_addr: %d.%d.%d.%d\n", arreglo[0],arreglo[1],arreglo[2],arreglo[3]);
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   memcpy(arreglo, &msg_to_server_addr.sin_addr.s_addr, 4);
   printf("Direccion del remitente: %d.%d.%d.%d\n", arreglo[0],arreglo[1],arreglo[2],arreglo[3]);
   printf("puerto del remitente: %d\n", msg_to_server_addr.sin_port);
   
   printf("2 + 5 = %d\n", res);
   close(s);
}

