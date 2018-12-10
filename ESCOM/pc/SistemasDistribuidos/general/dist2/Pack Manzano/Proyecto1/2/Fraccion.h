#ifndef FRACCION_H_
#define FRACCION_H_
#include <string>
using namespace std;
class Fraccion
{
private:
	int numerador, denominador;
public:
	Fraccion( int, int );
	double getValorReal( );
	string getReducida( );
};
#endif