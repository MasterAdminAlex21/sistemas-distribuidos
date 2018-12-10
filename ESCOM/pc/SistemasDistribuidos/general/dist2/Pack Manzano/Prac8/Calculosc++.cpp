#include <iostream>
#include <cmath>
using namespace std;
const int MAX=10000;

int main(){
	int i=1;
	float seno,coseno,tangente,logaritmo,raiz;
	while(i<MAX){
	seno+=sin(i);
	coseno+=cos(i);
	tangente+=tan(i);
	logaritmo+=log10(i);
	raiz+=sqrt(i);
	i++;
	}
	//cout << seno << endl;
	//cout << coseno << endl;
	//cout << tangente << endl;
	//cout << logaritmo << endl;
	//cout << raiz << endl;

	return 0;
}
