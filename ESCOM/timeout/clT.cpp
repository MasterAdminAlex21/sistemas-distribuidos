#include "Solicitud.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int numeroIte=atoi(argv[1]);
	Solicitud s;
	int total=0;
	int aux;
	int id = 0;
	for (int i = 0; i < numeroIte; i++)
	{
		aux=atoi( s.doOperation("10.100.70.230",7500,1,"0",id));
		//aux=atoi(s.doOperation("127.0.0.1",7300,1,"0", id));
		id++;
		printf("Consulta %d\n",aux);
		if(aux==total){
			int val = atoi(s.doOperation("10.100.70.230",7500,2,"1",id));
			if (val != -1){
				printf("Agregamos 1, confirmación:  %d\n", val);
				//printf("Agregamos 1, confirmación:  %s\n", s.doOperation("127.0.0.1",7300,2,"1", id));
				id++;
				total+=1;
			}
		}else{
			printf("Error no coinciden las cuentas\n");
			break;
		}
	}
	return 0;
}
