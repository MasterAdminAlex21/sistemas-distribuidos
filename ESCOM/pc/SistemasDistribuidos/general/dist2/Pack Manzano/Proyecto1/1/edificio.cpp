#include <iostream>
using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	double tiempo;
	cout << "Introduzca el tiempo\n";
	cin >> tiempo;
	
	cout << "La altura del edificio es: " << ( 0.5 ) * tiempo * tiempo * 9.81 << endl;

	return 0;
}
