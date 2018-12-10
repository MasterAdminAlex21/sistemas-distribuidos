#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int puerto = 7200;

int main(int argc, char *argv[])
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;

   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   msg_to_server_addr.sin_port = htons(puerto);

   char cadena[100];
   printf("%s\n",inet_ntoa(msg_to_server_addr.sin_addr));
   /*memcpy(cadena,&(msg_to_server_addr.sin_addr.s_addr),4);
   printf("%d.%d.%d.%d\n",cadena[0],cadena[1],cadena[2],cadena[3]);*/


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
   printf("%s\n",inet_ntoa(msg_to_server_addr.sin_addr));
   close(s);
}