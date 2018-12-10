#include "Fecha.h"
#include <iostream>
using namespace std;

int main(){
	Fecha a( 27 , 2, 2016 ), b(16, 10, 1995), c( 29, 2, 2000 );
	cout << a.dayOfWeek()<<"\n";
	cout << b.dayOfWeek()<<"\n";
	cout << c.dayOfWeek()<<"\n";


	return 0;
}