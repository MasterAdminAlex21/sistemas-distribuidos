#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	int max=70305;

	double i=0,seno=0,coseno=0,raizCuadrada=0,tangente=0,logaritmo=0;
	while(i<max)
	{
		seno+=sin(i);
		cout<<"Seno: "<<seno<<endl;
		coseno+=cos(i);
		cout<<"Coseno: "<<coseno<<endl;
		tangente+=tan(i);
		cout<<"Tangente: "<<tangente<<endl;
		logaritmo+=log10(i);
		cout<<"Logaritmo: "<<logaritmo<<endl;
		raizCuadrada+=sqrt(i);
		cout<<"Raiz Cuadrada: "<<raizCuadrada<<endl<<endl;
		i++;
	}
	return 0;
}