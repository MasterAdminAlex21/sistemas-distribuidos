
#include <iostream>
#include <vector>
#include "Coordenada.h"

using namespace std;

class PoligonoIrreg
{
	private:
		vector <Coordenada> vct;
	public:
		PoligonoIrreg();
		void addVertice(Coordenada a);
		void imprimeVertices();
};