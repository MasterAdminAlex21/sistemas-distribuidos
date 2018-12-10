
#include <stdio.h>
#include <math.h>

int main()
{
	long int i = 0;
	long int max = 50000000;
	double seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raizCuad = 0;

	while(i < max) {
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log10(i);
		raizCuad += sqrt(i);

		i++;
	}

	return 0;
}