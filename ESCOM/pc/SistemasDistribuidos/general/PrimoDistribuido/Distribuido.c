/* 
	Programa que recibe un númeor entero por consola
	y una lista de direcciones IP a quiénes distribuir el cálculo 
	de si un número es primo o no.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct in_addr IP;

unsigned validar_entrada( int, char **);
short isPrime(unsigned);
void * reservar_memoria(int n, unsigned);
void asignar_rangos(int , int *);

IP * IPs;
int COMP_NUM;
int * rangos;
char * ip_server = "127.0.0.1";
int pto_server = 8888;

int main(int argc, char * argv[])
{
	unsigned num = validar_entrada(argc, argv);
	int i, nums[2];

	rangos = (int *)reservar_memoria(COMP_NUM + 1, sizeof(int));
	asignar_rangos(num, rangos);

	/* Envio de rangos */
	struct sockaddr_in msg_ser, client_addr;
	int s;

	/* rellena la dirección del servidor*/
	bzero( (char *)&msg_ser, sizeof(msg_ser) );
	msg_ser.sin_family = AF_INET;
	msg_ser.sin_addr.s_addr = inet_addr(ip_server);
	msg_ser.sin_port = htons(pto_server);

	
	/* Enviar los rangos */
	for(int i = 0; i < COMP_NUM; i++)
	{
		s = socket(AF_INET, SOCK_DGRAM, 0);
		/* rellenar la dirección del cliente */
		bzero( (char *)&client_addr, sizeof(client_addr) );
		bind(s, (struct sockaddr *)&client_addr, sizeof(client_addr) );
		nums[0] = rangos[i];
		nums[1] = rangos[i + 1];
		sendto(s, (char *)nums, 3 * sizeof(int), 0, (struct sockaddr *)&msg_ser, sizeof(msg_ser) );
		close(s);
	}

	int vandera;
	for(int i = 0; i < COMP_NUM; i++)
	{
		short resp;
		int size;
		size = sizeof(cliente);
		vandera = 1;
		if((recibido = recvfrom(sock, &resp, sizeof(short), 0, (struct sockaddr*)&cliente, &size)) < 0){
			printf("\nError al recivir rangos");
			exit(0);
		}
		else
			printf("rango recibido\n");
		if (resp == 0){
			vandera = 0;
			break;
		}
	}

	if (vandera == 1){
		printf("es primo\n");
	}


	free(IPs);
	free(rangos);
	return 0;
}

unsigned validar_entrada(int argc, char ** argv)
{
	register int i;
	int valid;

	if(argc < 3)
	{
		perror("Número de argumentos no válido");
		exit(EXIT_FAILURE);	
	}

	unsigned long aux = strtoul(argv[1], NULL, 10);

	if( aux > UINT_MAX)
	{
		perror("El numero no es válido");
		exit(EXIT_FAILURE);
	}

	COMP_NUM = argc - 2;

	IPs = (IP *)reservar_memoria(COMP_NUM, sizeof(IP));

	for(i = 0; i < COMP_NUM; i++)
	{
		valid = inet_aton(argv[i + 2], &(IPs[i]));
		if( !valid )	
		{
			printf("Direccion %d no válida\n", i);
			perror("Dirección IP número no válida");
      		exit(EXIT_FAILURE);
		}
	}

	return (unsigned int)aux;
}

short isPrime(unsigned num)
{
	unsigned i;
	short isPrime = 1;
	for(i = 2; i < num; i++)
	{
		if( !(num%i) )
			isPrime = 0;
	}
	return isPrime;
}

void * reservar_memoria(int n, unsigned size)
{
	void * a = malloc(n * size);
	if(!a)
	{
		perror("Error en la asignación de memoria");
		exit(EXIT_FAILURE);
	}

	return a;
}

void asignar_rangos(int num, int * rangos)
{
	int skip = (num-2)/COMP_NUM + 1;
	int i;
	printf("Skip: %d\n", skip );

	rangos[0] = 2;

	for(i = 1; i < COMP_NUM; i++)
		rangos[i] = rangos[i - 1] + skip;

	rangos[COMP_NUM] = num;
}
