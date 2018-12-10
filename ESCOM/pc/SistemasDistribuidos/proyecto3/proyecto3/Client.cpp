#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(){
   int sock,bytes_recv,sin_size;
   struct sockaddr_in server_addr;
   struct hostent *host;
   char send_data[1024],recv_data[1024];
   host= (struct hostent *) gethostbyname((char *)"127.0.0.1");
   sock = socket(AF_INET, SOCK_DGRAM, 0);
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(5000);
   server_addr.sin_addr = *((struct in_addr *)host->h_addr);
   bzero(&(server_addr.sin_zero),8);
   sin_size = sizeof(struct sockaddr);
   while (1){
      printf("Type Something (q or Q to quit):");
      gets(send_data);
      sendto(sock, send_data, strlen(send_data), 0 ,(struct sockaddr *)&server_addr, sizeof(struct sockaddr));
      bytes_recv = recvfrom(sock,recv_data,1024,0,(struct sockaddr *)&server_addr, (unsigned int *)&sin_size);
      recv_data[bytes_recv]= '\0';
      printf("Received :%s\n",recv_data);
   }

}
