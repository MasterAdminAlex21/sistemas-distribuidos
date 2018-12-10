//cliente que envia los datos

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

using namespace std;

int puerto = 9876;
int armonico=1;
struct coordenada{
   double x;
   double y;
};

struct datos{
   int s;
   struct sockaddr_in addr;
};

void* generar(void *dato){//socket s,struct sockaddr_in addr){
   //enviamos las coordenadas que se generan
   struct datos *d=(struct datos*)dato;
   double y1=M_PI/2;
   for( double aux=-1;aux<=1;aux+=0.0001){
      for(int i=1;i<armonico;i++){
         y1+=((4*sin(aux*((i*2)-1))*M_PI)/(M_PI*((i*2)-1)));
      }
      struct coordenada *c;
      c=(struct coordenada*)malloc(sizeof(struct coordenada));
      c->x=aux;
      c->y=y1;
      sendto(d->s,(void*)c,sizeof(struct coordenada),0,(struct sockaddr*)&d->addr,sizeof(d->addr));
      free(c);
      y1=M_PI/2;
      printf("Paquete enviado\n");
   }
   //armonico+=1;
   pthread_exit(0);
}


void* eliminar(void *dato){//socket s, struct sockaddr_in addr){
   //aqui eliminamos los puntitos
   struct datos *d=(struct datos*)dato;
   double y1=M_PI/2;
   for( double aux=-1;aux<1;aux+=0.0001){
      for(int i=1;i<armonico;i++){
         y1+=((4*sin(aux*((i*2)-1))*M_PI)/(M_PI*((i*2)-1)));
      }
      struct coordenada *c;
      c=(struct coordenada*)malloc(sizeof(struct coordenada));
      c->x=aux;
      c->y=y1;
      sendto(d->s,(void*)c,sizeof(struct coordenada),0,(struct sockaddr*)&d->addr,sizeof(d->addr));
      free(c);
      y1=M_PI/2;
      printf("valores: x: %f\t y: %f\n",aux,y1);
   }
   if(armonico==5){
      armonico=1;
   }else{
      armonico+=1;
   }
   pthread_exit(0);
}

int main(void)
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;
   //char *mens={"15324\0"};
   //struct mensaje *msg;
   //msg=(struct mensaje*)malloc(sizeof(struct mensaje));
   
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

   struct datos *d;
   d=(struct datos*)malloc(sizeof(struct datos));
   d->s=s;
   d->addr=msg_to_server_addr;
   printf("crea los hilos\n");
   //aqui creamos los hilos 
   
   while(1){
      //aqui enviamos las coordenadas
      pthread_t envia;
      pthread_create(&envia,NULL,&generar,d);
      pthread_join(envia,NULL);

      pthread_t borra;
      pthread_create(&borra,NULL,&eliminar,d);
      pthread_join(borra,NULL);

   }


   //sendto(s, (void*)msg,sizeof(struct mensaje) , 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));

   close(s);
}

