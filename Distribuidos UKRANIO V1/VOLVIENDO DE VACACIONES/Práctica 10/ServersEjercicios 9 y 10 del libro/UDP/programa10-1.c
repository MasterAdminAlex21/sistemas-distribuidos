#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
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
   msg_to_server_addr.sin_addr.s_addr = inet_addr("10.100.69.234");
   msg_to_server_addr.sin_port = htons(puerto);
   
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(6666);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 9999;
   num[1] = 1; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   
   struct sockaddr_in *sin = (struct sockaddr_in *)&msg_to_server_addr;
   unsigned char *ip = (unsigned char *)&sin->sin_addr.s_addr;

   printf("\nConnection from: %d.%d.%d.%d:%d\n", ip[0], ip[1], ip[2], ip[3], (int)ntohs(msg_to_server_addr.sin_port));

   printf("\n%d+%d=%d\n", num[0],num[1],res);
   close(s);
}

