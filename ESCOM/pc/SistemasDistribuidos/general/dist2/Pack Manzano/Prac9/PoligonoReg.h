#ifndef POLIGONOREG_H_
#define POLIGONOREG_H_
#include <vector>
#include "Coordenada.h"
#include "PoligonoIrreg.h"
using namespace std;
class PoligonoReg : public PoligonoIrreg{
private:
	int lados;
public:
    PoligonoReg( int l = 3);
    double obtieneArea();
    float obtieneAreaF();
 };
#endif