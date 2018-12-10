#include <iostream>
#include "Coordenada.h"
#include "PoligonoReg.h"
#include "PoligonoIrreg.h"
using namespace std;

int main( )
{
	PoligonoReg pol;
	for( int i = 3; i <= 6; i++ ){
		cout << endl;
		cout.precision(5);
		pol = PoligonoReg(i);
		pol.imprimeVertices();
		cout.precision(40);
		cout << pol.obtieneArea()<< endl;
		
		cout << pol.obtieneAreaF()<< endl;
	}
	
	pol = PoligonoReg(10000000);
	cout << "\nAproximado de PI: " <<pol.obtieneArea()<<endl;

	return 0;
} 