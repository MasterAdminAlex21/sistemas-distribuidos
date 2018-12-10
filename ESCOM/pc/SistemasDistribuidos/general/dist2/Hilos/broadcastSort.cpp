/* Este programa muestra la sincronizaciòn en la impresion de dos hilos */
#include "SocketDatagrama.h"

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <set>

using namespace std;

SocketDatagrama sock(0);

sem_t mutex1;
sem_t mutex2;
set <string> tabla;

void* Hilo1(void*);
void* Hilo2(void*);
void* Hilo3(void*);

int main(void){
   pthread_t th1, th2, th3;
   
   // Inicializa los semaforos
   sem_init(&mutex1, 0, 1);
   sem_init(&mutex2, 0, 0);
   
   // Crea hilos
   pthread_create(&th1, NULL, &Hilo1, NULL);
   pthread_create(&th2, NULL, &Hilo2, NULL);
   pthread_create(&th3, NULL, &Hilo3, NULL);
   
   // Esperar a que los hilos terminen
   pthread_join(th1, NULL);
   pthread_join(th2, NULL);
   pthread_join(th3, NULL);
   
   exit(0);
}

void* Hilo1(void*){
   while(true){
      sem_wait(&mutex1);
      int puerto = 7200;
      int tam = 1000;
      int *num = new int[2];
      num[0] = 1;
      num[1] = 919;
      char ip[16];
      sock.setBroadcast();
      sprintf(ip, "192.168.0.255");
      PaqueteDatagrama paks((char *)num, 8, ip, puerto);
      sock.envia(paks);
      sleep(3);
      system("clear");
      sem_post(&mutex2);
   }
}

void* Hilo2(void*){
   while(true){
      sem_wait(&mutex2);
      system("clear");
      cout << "IPs ordenadas: " << endl;
      for(set<string> :: iterator it = tabla.begin(); it != tabla.end(); it++)
         cout << *it << endl;
      tabla.clear();
      sem_post(&mutex1);
   }
}

void* Hilo3(void*){
   while(1){
      PaqueteDatagrama rev(4);
      sock.recibe(rev);
      string a = rev.obtieneDireccion();
      tabla.insert(a);
   }
}

