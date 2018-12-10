#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_
#include "Rectangulo.h"
#include <set>
using namespace std;
class Ortoedro
{
 private:
    Rectangulo rec[ 6 ];
 public:
 	Ortoedro( Coordenada r1, Coordenada r2 );
    set< Coordenada > getVertices();
    double getArea();
    double getVolumen();
};
#endif