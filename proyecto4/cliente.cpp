#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include<stdlib.h>
using namespace std;

int puerto = 9876;

struct mensaje{
   int a;
   double b;
   float c;
   long d;
};

int main(void)
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
   //char *mens={"15324\0"};
   struct mensaje *msg;
   msg=(struct mensaje*)malloc(sizeof(struct mensaje));
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   msg_to_server_addr.sin_port = htons(puerto);
   
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2321;
   num[1] = 5235; /*rellena el mensaje */

   msg->a=1234;
   msg->b=3611.12354651;
   msg->c=3.1415;
   msg->d=355612351;

   printf("tamaño:\n entero: %ld \tfloat: %ld\n double: %ld \tlong: %ld",sizeof(int),sizeof(float),sizeof(double),sizeof(long));
   sendto(s, (void*)msg,sizeof(struct mensaje) , 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   printf("Datos enviados: \nnum1: %d\t num2: %f\nnum3: %f\t num4: %ld\n tamaño: %ld\n",msg->a,msg->b,msg->c,msg->d,sizeof(struct mensaje) );
   /* se bloquea esperando respuesta */
   //recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   //printf("2 + 5 = %d\n", res);
   close(s);
}

