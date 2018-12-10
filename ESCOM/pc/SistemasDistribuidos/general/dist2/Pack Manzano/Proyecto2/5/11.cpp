#include "Fraccion.h"
using namespace std;

int main(){
	Fraccion a,b( 5 , 3 ),c;
	c.setFraccion( 2 , 7 );

	( a + b ).imprimeFraccion();
	( a - c ).imprimeFraccion();
	( b * c ).imprimeFraccion();
	( b / c ).imprimeFraccion();

}