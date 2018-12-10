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
   int bandera;//0 para limpiar, 1 para imprimir
   double x;
   double y;
};

struct datos{
   int s;
   struct sockaddr_in addr;
};

//pthread_mutex_t semaforo;

void* generar(void *dato){//socket s,struct sockaddr_in addr){
   //enviamos las coordenadas que se generan
   while(1){
      //pthread_mutex_lock(&semaforo);
      printf("Empieza a generar\n");
   struct datos *d=(struct datos*)dato;
   double y1=M_PI/2;
   for( double aux=-1;aux<=1;aux+=0.0001){
      for(int i=1;i<=armonico;i++){
         y1+=((4*sin(aux*((i*2)-1)*M_PI))/(M_PI*((i*2)-1)));
      }
      struct coordenada *c;
      c=(struct coordenada*)malloc(sizeof(struct coordenada));
      c->bandera=1;
      c->x=aux;
      c->y=y1;
      sendto(d->s,(void*)c,sizeof(struct coordenada),0,(struct sockaddr*)&d->addr,sizeof(d->addr));
      free(c);
      char reply[10];
      recvfrom(d->s,reply,sizeof(reply),0,(struct sockaddr*)&d->addr,(unsigned int*)sizeof(d->addr));
      //printf("valores: x: %f\t y: %.16f\n",aux,c->y);*/
      y1=M_PI/2;
      //printf("Paquete enviado\n");
      usleep(300);
   }
   //pthread_mutex_unlock(&semaforo);
   if(armonico==50){
      armonico=1;
   }else{
      armonico+=1;
   }
   //sleep(2);
   }
   //sleep(5);
   //armonico+=1;
   pthread_exit(0);
}


void* eliminar(void *dato){//socket s, struct sockaddr_in addr){
   //aqui eliminamos los puntitos
   while(1){
     // pthread_mutex_lock(&semaforo);
      printf("Empieza a borrar\n");
      int arm=armonico;
   struct datos *d=(struct datos*)dato;
   double y1=M_PI/2;
   for( double aux=-1;aux<1;aux+=0.0001){
      for(int i=1;i<=arm;i++){
         y1+=((4*sin(aux*((i*2)-1)*M_PI))/(M_PI*((i*2)-1)));
      }
      struct coordenada *c;
      c=(struct coordenada*)malloc(sizeof(struct coordenada));
      c->bandera=0;
      c->x=aux;
      c->y=y1;
      sendto(d->s,(void*)c,sizeof(struct coordenada),0,(struct sockaddr*)&d->addr,sizeof(d->addr));
      free(c);
      char reply[10];
      recvfrom(d->s,reply,sizeof(reply),0,(struct sockaddr*)&d->addr,(unsigned int*)sizeof(d->addr));
      //printf("valores: x: %f\t y: %.16f\n",aux,y1);*/
      y1=M_PI/2;
      usleep(300);
   }
   //sleep(5);
   /*
   if(armonico==50){
      armonico=1;
   }else{
      armonico+=1;
   }*/
  // pthread_mutex_unlock(&semaforo);
   //sleep(2);
   }
   pthread_exit(0);
}

int main(int argc, char *argv[])
{
   if(argc!=2){
      printf("uso: %s <ip_server>",argv[0]);
      exit(0);
   }
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);//("10.100.70.252");
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
   pthread_t envia,borra;
   //pthread_mutex_init(&semaforo,NULL);   
   pthread_create(&envia,NULL,&generar,d);
   sleep(6);
   pthread_create(&borra,NULL,&eliminar,d);

   pthread_join(envia,NULL);
   pthread_join(borra,NULL);
   //while(1){
      //aqui enviamos las coordenadas
      
      /*pthread_t envia;
      pthread_create(&envia,NULL,&generar,d);
      pthread_join(envia,NULL);

      pthread_t borra;
      pthread_create(&borra,NULL,&eliminar,d);
      pthread_join(borra,NULL);
*/
      //break;

   //}

   close(s);
}

