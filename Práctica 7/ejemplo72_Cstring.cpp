#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int main() 
{

//  Comienza Ejercicio 1

/*
	int n;
	string line;
	cin >> n;
	getline(cin, line);
	cout << n;
*/	

/*Solamente recibe el tipo de dato inicical, de forma que no lo concatena int con char etc.  */

//Comienza Ejercicio 2


string cadena("ESCOM");
cout << cadena[6] << endl;


// Cadena de prueba con elemento bien señalado
string cadena2("ESCOM2");
cout << cadena2.at(0) << endl;
cout << cadena2.at(1) << endl;
cout << cadena2.at(2) << endl;
cout << cadena2.at(3) << endl;
cout << cadena2.at(4) << endl;
cout << cadena2.at(5) << endl;
cout << cadena2.at(6) << endl;

}
