#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_
#include <vector>
#include "Coordenada.h"
using namespace std;
class PoligonoIrreg{
private:
	vector < Coordenada > vertices;
	static int veces;
	int pos;
public:
    PoligonoIrreg();
    void anadeVertice( Coordenada );
    void imprimeVertices();
    int getVeces();
 };
#endif