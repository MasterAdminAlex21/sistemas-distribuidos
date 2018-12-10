#include "Servidor.h"
#include <unistd.h>
using namespace std;

int main( int argc, char* argv[] ){
	if( argc != 2 ){
		printf("Forma de uso: programa porcentaje \n");
		exit(0);
	}

	for( int i = 0; i < 8; i++ ){
		if( fork() == 0 )
			Servidor serv( i , atoi( argv[1] ), 1 );	
	}
	for( int i = 0; i < 8; i++ ){
		wait(0);
	}
}