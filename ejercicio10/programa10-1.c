#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include<stdlib.h>

//cliente

int puerto = 7200;

int main(int argv, char *argc[])
{
   if(argv<2){
      printf("uso: %s ip_server",argc[0]);
      exit(-1);
   }
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argc[1]);//
   msg_to_server_addr.sin_port = htons(puerto);
   
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;

   //ejercicio 1
   unsigned char ip[6];
   memcpy(ip,&msg_to_server_addr.sin_addr.s_addr,6);
   //

   printf("%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);

   //ejercicio2
   memcpy(ip,&msg_to_server_addr.sin_addr.s_addr,4);
   printf("Direccion del servidor: %d.%d.%d.%d :: ",ip[0],ip[1],ip[2],ip[3]);
   printf("puerto: %d\n",msg_to_server_addr.sin_port);
   //
   printf("2 + 5 = %d\n", res);
   close(s);
}

