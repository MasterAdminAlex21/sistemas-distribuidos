#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int puerto = 7200;

double funcion(int n,double x){
	double y = 4.0/3.1416;
	int i;
	double aux = 0.0;
	for(i=0;i<n;i++)
		aux+= 1.0/(i*2.0+1.0) * sin((i*2.0+1.0)*x);
	printf("%lf\n",aux*y);
	return y*aux;
}

int main(int argc, char *argv[]){
   int ite = 0;
   scanf("%d", &ite);
   //getchar();
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[3], res,i;
   double x;
   int xe = -400; 
   srand(time(NULL));
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   msg_to_server_addr.sin_port = htons(puerto);
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   client_addr.sin_port = htons(9000);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   for(i=0;i<800;i++){
	    x = -3.1416 + i* 3.14/400.0;
		num[0] = xe;
		xe++;
		printf("x = %d\n",num[0]);
		num[1] = (int) (funcion(ite, x) * 233.0); 
		printf("y= %d\n",num[1]);
		num[2]= 1;
		printf("%d\n",num[2]);
		sendto(s, (char *)num, 3 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
		//getchar();
      usleep(30000);
   }
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   printf("2 + 5 = %d\n", res);
   close(s);
}

