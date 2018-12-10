#include "Circulo.h"
using namespace std;

int main(){
	Circulo a( 100, 200 , 5 ), b;

	a.imprimeEscala();
	a.imprimeCirculo();
	a.setEscala( 10 );
	b.imprimeCirculo();
	b.imprimeEscala();
	b.setEscala( 30 );
	b.imprimeEscala();

	return 0;
}