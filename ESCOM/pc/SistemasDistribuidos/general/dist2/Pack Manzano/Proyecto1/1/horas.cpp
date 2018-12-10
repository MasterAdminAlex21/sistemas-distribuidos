#include <iostream>
using namespace std;

int main(){
	int N, horas,minutos, segundos;
	cout << "Introduzca el número de segundos: \n";
	cin >> N;
	horas = N/3600;
	minutos = ( N%3600 )/60;
	segundos = ( N % 3600 ) % 60;
	cout << horas << " horas, " << minutos << " minutos y " << segundos << " segundos\n";

	return 0;
}