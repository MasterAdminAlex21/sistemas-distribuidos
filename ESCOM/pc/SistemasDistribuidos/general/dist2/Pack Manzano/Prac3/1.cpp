#include <iostream>
#include "Temperatura.h"
using namespace std;

int main(){
	
	Temperatura test;
	test.setTempKelvin(300.5);
	test.imprimeCelsius();

	return 0;	
}