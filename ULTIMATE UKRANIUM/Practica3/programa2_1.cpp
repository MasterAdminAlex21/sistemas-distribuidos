
#include <iostream>
#include <stdlib.h>
#include "Fecha.h"

using namespace std;

/*int masVieja(Fecha fecha1, Fecha fecha2)
{
	int f1 = fecha1.convierte();
	int f2 = fecha2.convierte();

	if(f1 == f2)
		return 0;
	else if(f1 > f2)
		return 1;
	else 
		return -1;
}*/

/*int masVieja(Fecha &fecha1, Fecha &fecha2)
{
	int f1 = fecha1.convierte();
	int f2 = fecha2.convierte();

	if(f1 == f2)
		return 0;
	else if(f1 > f2)
		return 1;
	else 
		return -1;
}*/

//Para pasar por referencia en C es: &variable
int masVieja(Fecha *fecha1, Fecha *fecha2)
{
	int f1 = fecha1->convierte();
	int f2 = fecha2->convierte();

	if(f1 == f2)
		return 0;
	else if(f1 > f2)
		return 1;
	else 
		return -1;
}

int main()
{
	cout << "C \n\n";
	//true rand
	srand(time(0));
	Fecha a, b;
	a.inicializaFecha(rand() % 31 + 1, rand() & 12 + 1, rand() % 2018 + 1);
	b.inicializaFecha(rand() % 31 + 1, rand() & 12 + 1, rand() % 2018 + 1);
	a.muestraFecha();
	b.muestraFecha();

	for(int i = 0; i < 50000; i++) {
		int x = masVieja(&a, &b);
	}
}
