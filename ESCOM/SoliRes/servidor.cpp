#include <sys/types.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include <algorithm>
#include "Respuesta.h"
using namespace std;

int puerto = 7300;

struct messageSC {   
   char nombre[45];
   uint32_t num[10];
} mensaje;

int main()
{

	Respuesta res=Respuesta(puerto	);
	SocketDatagrama socket = SocketDatagrama(puerto);	
	uint32_t num[10],aux;
	
	while(1)
	{
		PaqueteDatagrama datagrama = PaqueteDatagrama( 10 * sizeof(uint32_t));
		socket.recibe(&datagrama);	
		memcpy(mensaje.num, datagrama.obtieneDatos(), 10*sizeof(uint32_t));
		printf("el numero 1 es %u",mensaje.num[1]);
		printf("el numero 2 es %u",mensaje.num[2]);
		
		sort(mensaje.num, mensaje.num+10);
				
		PaqueteDatagrama databack =  PaqueteDatagrama((char*) &mensaje.num,10* sizeof(int), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
		socket.envia(&databack);
		PaqueteDatagrama databack2 =  PaqueteDatagrama((char*) &mensaje.nombre,45* sizeof(char), datagrama.obtieneDireccion(), datagrama.obtienePuerto());
		socket.envia(&databack2);
	}
}

