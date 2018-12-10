#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>
#include "Coordenada.h"
using namespace std;
class PoligonoIrreg{
protected:
	vector < Coordenada > vertices;
	int pos;
public:
    PoligonoIrreg();
    void anadeVertice( Coordenada );
    void imprimeVertices();
    int getVeces();
    void ordenaA();
 };
#endif