#include "Circulo.h"
#include <iostream>
using namespace std;

double Circulo::escala = 0;

Circulo::Circulo(int x_, int y_, double r_) : x(x_), y(y_), radio(r_){
}

void Circulo::setEscala( double value ){
	escala = value;
}

void Circulo::imprimeEscala(){
	cout << "La escala actual es: " << escala<<"\n";
}

void Circulo::imprimeCirculo(){
	cout << "Circulo con radio en ( " << x << " , " << y <<" ) y radio: " << radio<<"\n"; 
}
