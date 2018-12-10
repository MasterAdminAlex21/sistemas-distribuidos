#include <iostream>
#include "Fraccion.h"
using namespace std;

int main(){
	Fraccion test( 18 , 15 );
	cout << test.getValorReal() << " " << test.getReducida()<<endl;

	return 0;
}