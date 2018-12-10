#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Coordenada.h"
#include <set>
using namespace std;
class Rectangulo
{
 private:
    Coordenada coord[4];
 public:
 	Rectangulo( );
 	Rectangulo( Coordenada, Coordenada, Coordenada, Coordenada );
    set< Coordenada > getVertices();
    double getArea();
    Coordenada getUno();
    Coordenada getDos();
};
#endif