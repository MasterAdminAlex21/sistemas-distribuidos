#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <stdlib.h>
#include <set>
#include <cstring>
#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <cstring>
using namespace std;

int serv = 7200;
int puerto = 8000;
 
set< string > ips;

sem_t mutex1;
sem_t mutex2;

void *Hilo1(void *);
void *Hilo2(void *);
void *Hilo3(void *);
PaqueteDatagrama *paquete;
SocketDatagrama *sock;
char ipServidor[100];
int num[ 2 ];

int main( int argc, char *argv[] ){
	
	num[0] = 5; num[1] = 30;
	strcpy(ipServidor, argv[1]);
	paquete = new PaqueteDatagrama( (char *)num, 2*sizeof(int), argv[1] , serv );
	sock = new SocketDatagrama( puerto );

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

	return 0;
}

void *Hilo1(void *){
	//cout << "Hilo 1" << endl;
	while(1){
    	sem_wait(&mutex1);
		sock->setBroadcast();
		//cout << "envio"<<endl;
		paquete = new PaqueteDatagrama( (char *)num, 2*sizeof(int), ipServidor , serv );
		int tam = sock->envia( *paquete );
		sleep(5);
		//cout << "Envió broadcast"<< endl;
		sem_post(&mutex2);
	}
	pthread_exit(0);
}

void *Hilo2(void * ){
	//cout << "Hilo 2" << endl;
	while(1){
		sem_wait(&mutex2);
		system("clear");
		for( set< string >::iterator it= ips.begin(); it != ips.end(); it++ ){
			cout << *it << endl;
		}
		//cout << "Imprime"<<endl;
		ips.clear();
		sleep(5);
		sem_post(&mutex1);
	}
	pthread_exit(0);
}

void *Hilo3(void *){
	//cout << "Hilo 3" << endl;
	while(1){
		paquete = new PaqueteDatagrama( sizeof(int) );
		int tam = sock->recibe( *paquete );
		int res;
		memcpy( &res, paquete->obtieneDatos(), tam );
		ips.insert( paquete->obtieneDireccion() );
	}
	
	pthread_exit(0);
}