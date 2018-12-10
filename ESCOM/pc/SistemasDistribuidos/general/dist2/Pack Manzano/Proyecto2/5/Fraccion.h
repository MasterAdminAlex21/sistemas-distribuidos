#ifndef FRACCION_H_
#define FRACCION_H_
#include <string>
using namespace std;
class Fraccion
{
private:
	int numerador, denominador;
public:
	Fraccion( int = 1, int = 1);
	double getValorReal( );
	Fraccion getReducida( );
	void setFraccion( int , int );
	void imprimeFraccion();
	Fraccion operator+( Fraccion& );
	Fraccion operator*( Fraccion& );
	Fraccion operator/( Fraccion& );
	Fraccion operator-( Fraccion& );

};
#endif