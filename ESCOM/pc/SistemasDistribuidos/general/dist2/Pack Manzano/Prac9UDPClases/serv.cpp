#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int puerto = 7200;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(void)
{
   int num[65500];
   int s, res;
   socklen_t clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   while(1) {
      cout << "Esperando cliente\n";
      int tam = recvfrom(s, (char *) num, (int)65000, 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      cout << "Recibió\n";

      int N = tam/4;

      /*for (int i = 0; i < N; ++i){
         cout << num[i]<<" ";
      }
      cout << "\n";
      */
      qsort( num, N, sizeof(int), compare );
      
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
      sendto(s, (char *)&num, N*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
      cout << "Envió\n";
   }
}

