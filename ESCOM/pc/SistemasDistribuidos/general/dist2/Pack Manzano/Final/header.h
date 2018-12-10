/*Códigos de error */
#define PETICION 1
#define ALIVE 2
#define UPDATE 3
#define RESPUESTA 4
#include <inttypes.h>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
//Operación correcta
//Operación desconocida
//Error en un parámetro
//Error en disco u otro error de E/S
/* Formato del mensaje que viaja del cliente hacia el servidor. El tipo de dato numérico
uint32_t está definido en inttypes.h y es consistente entre computadoras distintas e
independiente del sistema operativo */

struct messageSS{

uint32_t tipo;
//uint32_t noServidorMuerto;
uint32_t noEmisor;
char peticion[400];
};

struct messageSC{
	uint32_t actualizar;
	uint32_t tipo;
	char nombre[100];
	int offset;
};
