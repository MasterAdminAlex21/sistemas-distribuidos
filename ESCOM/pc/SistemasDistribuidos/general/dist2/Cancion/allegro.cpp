#include <allegro.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "SocketDatagrama.h"

using namespace std;


SocketDatagrama sock(0);

bool REPRODUCE = false;
int positionActual = 0;

void* Play(void*);
void* Recibe(void*);


int main() {
	pthread_t th1, th2;
   	pthread_create(&th1, NULL, &Play, NULL);
   	pthread_create(&th2, NULL, &Recibe, NULL);
	int puerto = 7200;
	int *num = new int[2];
	
	char ip[16];
	sprintf(ip, "192.168.43.142");
	while(1){
		num[0] = positionActual;
		num[1] = REPRODUCE;
		PaqueteDatagrama paks((char *)num, 8, ip, puerto);
		usleep(50000);
		sock.setTimeout(0, 100000);
		sock.envia(paks);
	}

	// Terminar: 
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	return 0;
}

void* Recibe(void *){
	int* num = new int[2];
	while(1){
		PaqueteDatagrama tiempo(8);
		sock.recibe(tiempo);
		num = (int*)tiempo.obtieneDatos();
		positionActual = num[0];
		REPRODUCE = num[1];
	}
}

void* Play(void*){
	while(1){
		if(!REPRODUCE)
			continue;
		SAMPLE *audio;
		int vox;

		// Inicializa la librería de Allegro "liballeg.so.4.4.2" :
		if (install_allegro(SYSTEM_AUTODETECT, NULL, NULL)!= 0) {
			allegro_exit();
			printf("Error: no se puede inicializar la librería ''allegro' !");
			exit(-1);
		}

		// Instala el módulo de sonido:
		if (install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL)!= 0) {
			allegro_exit();
			printf("Error: imposible la instalación del módulo de sonido !");
			exit(-1);
		}

		// Sube el archivo wav:
		audio = load_wav("the_edge.wav");
		if (!audio) {
			allegro_exit();
			printf("Error: imposible subir el archivo !");
			exit(-1);
		}

		// Extrae información general del archivo wav:
		printf("Resolución de muestreo: %dbit\n", audio->bits);
		printf("Canales de salida: %d\n", audio->stereo*-1+1);
		printf("Frecuencia de muestreo: Hz %d\n", audio->freq);
		// Ejecuta el file wav:

		vox = play_sample(audio, 255, 128, 1000, 0);
		voice_set_position(vox, positionActual);
		do {
			positionActual = voice_get_position(vox);
			printf("Ejecución de la muestra de audio n. %d\r", positionActual);
		} while (positionActual != -1);

		destroy_sample(audio);
		remove_sound();
	}
}