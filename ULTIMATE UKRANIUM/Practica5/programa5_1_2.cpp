
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

#include "PoligonoIrreg.h"

using namespace std;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    double res = fMin + f * (fMax - fMin);
    return roundf(res* 1000.0) / 1000.0;
}


int main()
{
	//srand(time(0));	
	int n;
	PoligonoIrreg p1;
 static double x1=1;
	std::vector <PoligonoIrreg> p;
	p.reserve(1000);
 unsigned int global;
	for(int i = 0; i < 1000; i++)
		
	{
		n=rand()%20;
		/*PoligonoIrreg p1(x1);
		p1.addVertice(a);
		p[i]=p1;*/
		for(int j=0;j<n;j++){
			double x = fRand(-100, 100);
		 double y = fRand(-100, 100);
		 Coordenada a(x,y);
		 p1.addVertice(a);		
		}global +=n;
		//p.push_back(p1);//*/
		p[i]=p1;

	}

 p[13].imprimeVertices();
	cout << "tamaño del vector: "<<p.size()<<endl;
 cout <<"numero total de vertices: "<<global<<endl;
	//cout<<"valor de n: "<<n<<endl;
/*	for(int i=0;i<n;i++){
		p[i].imprimeVertices();
	}*/

	return 0;
}

