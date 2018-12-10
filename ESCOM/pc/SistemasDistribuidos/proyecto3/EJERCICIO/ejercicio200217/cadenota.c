#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define Factor 10000

int veces(char* cadena,const char* subcadena, int tam){
	int count=0,i;
	for(i=0;i<tam;i++){
		if(cadena[i] == subcadena[0] && cadena[i+1] == subcadena[1] && cadena[i+2] == subcadena[2])
			count++;
		i+=3;	
	}
	return count;
}
int main()
{
	srand(time(NULL));
	int i;
	long long int tam = 26 * 26 * 26 *  4 * Factor;
	char * cadena = (char*) malloc (sizeof(char)* tam);
		for(i=0;i<tam;i++)
		{
			cadena[i] = rand()%26 + 65;
			i++;
			cadena[i] = rand()%26 + 65;
			i++;
			cadena[i] = rand()%26 + 65;
			i++;
			cadena[i] = ' ';
		}
	//for(i=0;i<tam;i++)
	//	printf("%c",cadena[i]);
	printf("\n NUMERO DE VECES %d \n", veces(cadena,"IPN",tam));
	free(cadena);
	return 0;
}



