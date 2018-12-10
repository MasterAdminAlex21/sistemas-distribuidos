#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include "Archivo.h"
#include <iostream>
#include <stdlib.h>
#include "header.h"
#include <string.h>
#include <map>
#include <semaphore.h>
#include <stdio.h>
#include <vector>
#include <pthread.h>
using namespace std;

int tam;
int noServ;
int puerto;
char ipGrupo[100];
int portDefault = 9403;
int portPaquetes = 9500;
int vivos[4];
char ipCliente[30];
int contadorVivos = 1;
sem_t mutex1;
sem_t mutex2;
messageSS msg;
messageSC envia;
map < string, int > mapa;
map < int, string > mapa2;
SocketMulticast *sm;
PaqueteDatagrama *pd, *paquete;
SocketDatagrama *soc, *socRecv, *sockAux;
void *Hilo1(void *);
void *Hilo2(void *);
void *Hilo3(void *);

int main( int argc, char *argv[] ){
	sm = new SocketMulticast( atoi(argv[2]) );
	soc = new SocketDatagrama( 0 );
	socRecv = new SocketDatagrama( portDefault );
	sockAux = new SocketDatagrama( portPaquetes );
	noServ = atoi(argv[3]);
	strcpy(ipGrupo, argv[1]);
	mapa[ argv[4] ] =  1;
	mapa[ argv[5] ] =  2;
	mapa[ argv[6] ] =  3;
	mapa2[1] = argv[4];
	mapa2[2] = argv[5];
	mapa2[3] = argv[6];

	puerto = atoi( argv[2] );
	pthread_t th1, th2, th3;

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

int redistribuir( int pos, int accion ){
	if( accion == 1 ){
		vivos[pos] = 1;
	}
	else{
		vivos[pos] = 0;
	}
}

void *Hilo1(void *){
	int turno = 1;
	while(1){
		sem_wait(&mutex1);
		
		if( turno != noServ ){
			msg.noEmisor = noServ;
			msg.tipo = ALIVE;
			soc->setTimeout(0, 35000);
			char ipTemp[100];
			strcpy(ipTemp, mapa2[turno].c_str());
			pd = new PaqueteDatagrama( (char *)&msg , sizeof( msg ), ipTemp , portDefault);

			int i;
			for( i = 0; i < 5 ; i++ ){
				soc->envia( *pd );
				tam = soc->recibeTimeout( *pd );
				if( tam >= 0 ){
					memcpy( &msg, pd->obtieneDatos(), tam );
					if( msg.tipo == UPDATE && msg.noEmisor == turno )
						break;
					else
						tam = -1;
				}
			}

			if( tam >= 0 ){
				printf("%c %d\n", 'v', turno);
				redistribuir( turno, 1 );
			}
			else{
				printf("%c %d\n", 'm', turno);
				redistribuir( turno, 0 );
			}
  		}
		turno = (turno)%3 + 1;
		sem_post(&mutex2);
	}
	//pthread_exit(0);
}

int calculaInf( int tam ){
	double tam2 = tam;
	double num = contadorVivos;
	if( contadorVivos == 1 ) return 0;
	if( contadorVivos == 3 ) return (int)((tam2/3) * (noServ-1));
	for( int i = 0; i < 4; i++ ){
		if( vivos[i] && i != noServ )
			if( i < noServ )
				return (int)( tam/2 );
			else
				return 0;
	}
}

int calculaSup( int tam ){
	double tam2 = tam;
	if( contadorVivos == 1 ) return tam;
	if( contadorVivos == 3 ) return (int)((tam2/3) * (noServ));
	for( int i = 0; i < 4; i++ ){
		if( vivos[i] && i != noServ )
			if( i < noServ )
				return tam;
			else
				return (int) (tam/2);
	}
}

void *Hilo2(void * ){
	while(1){
		//cout << "Hilo 2" << endl;
		sem_wait(&mutex2);
		pd = new PaqueteDatagrama( sizeof( messageSS ) );
		tam = sm->recibeTimeout( *pd, ipGrupo, 0, 50000 );

		if( tam >= 0 ){
			memcpy( &msg, pd->obtieneDatos(), tam );
			switch( msg.tipo ){
				case PETICION:{
					cout << "Peticion" << endl;
					envia.tipo = 4;
					contadorVivos = 1;
					for( int i = 0; i < 4; i++ ){
						if( vivos[i] )contadorVivos++;
					}
					
					Archivo origen("header.h", O_RDONLY);
					
					vector<string> lib = origen.buscaLibros();
					vector<int> v;
 
					vector< pair< string, int > > res;
					int limInf = 0;//calculaInf( lib.size() );
					int limSup = lib.size();//calculaSup( lib.size() );
					char nombre[400], buscar[200];
					strcpy( buscar, msg.peticion );
					int contador = 0;
					for( int i = limInf; i < limSup; i++  ){
						lib[i] = "./LIBROS/"+lib[i];
						strcpy(nombre, lib[i].c_str());
						v = origen.buscaOcurrencia( nombre, buscar);
						for( int j = 0; j < v.size(); j++ ){
							//cout<<"Libro: " << lib[i]<< v[j] <<endl;
							res.push_back( make_pair( nombre, v[j] ) );
							contador++;
						}
					}
					
					msg.tipo = UPDATE;
					msg.noEmisor = contador;
					//cout << "Contador:"<<contador<<" " << pd->obtieneDireccion() <<endl;
					pd = new PaqueteDatagrama( (char *)&msg , sizeof( msg ), "192.168.43.28", portPaquetes );
					sockAux->envia( *pd );

					for( int j = 0; j < res.size(); j++ ){
						//pd = new PaqueteDatagrama( sizeof( messageSS ) );
						//int tam2 = sockAux->recibe( *pd );
						//memcpy( &msg, pd->obtieneDatos(), tam2 );
						//cout << "Recibido :"<< msg.tipo<<" " << msg.noEmisor  << endl;
						//if( msg.tipo == -1 ) break;
						msg.noEmisor = res[j].second;
						strcpy(msg.peticion, res[j].first.c_str());
						pd = new PaqueteDatagrama( (char *)&msg , sizeof( msg ), pd->obtieneDireccion(), pd->obtienePuerto() );
						sockAux->envia( *pd );
						cout<<"Libro: " << res[j].first<< " "<<res[j].second <<endl;
					}
					
				}
				break;
				case ALIVE:{
					contadorVivos = 1;
					for( int i = 0; i < 4; i++ ){
						if( vivos[i] )contadorVivos++;
					}
					cout << "Alive"<< contadorVivos <<endl;
					msg.tipo = 4;
					msg.noEmisor = contadorVivos;
					strcpy(ipCliente, pd->obtieneDireccion());
					pd = new PaqueteDatagrama( (char *)&msg , sizeof( msg ), pd->obtieneDireccion(), pd->obtienePuerto() );
					
					//cout << "Alive ip:" << pd->obtieneDireccion() << endl;
					soc->envia( *pd );
				}
				break;
			}
		}

		sem_post(&mutex1);
	}
	//pthread_exit(0);
}

void *Hilo3(void * ){
	while(1){
		paquete = new PaqueteDatagrama( sizeof( messageSS ) );
		int recibido = socRecv->recibe( *paquete );
		messageSS mensaje;
		mensaje.tipo = 3;
		mensaje.noEmisor = noServ;
		paquete = new PaqueteDatagrama( (char *)&mensaje , sizeof( mensaje ), paquete->obtieneDireccion() , paquete->obtienePuerto());
		socRecv->envia( *paquete );
	}
	
	pthread_exit(0);
}

