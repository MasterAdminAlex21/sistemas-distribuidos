#include "Fecha.h"
#include <iostream>
using namespace std;

int main(){
	Fecha a( 20160227l ), b(16, 10, 1995), c( 29, 2, 2000 );
	a.muestraFecha();
	b.muestraFecha();
	c.muestraFecha();


	return 0;
}