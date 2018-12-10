#include <iostream>
#include <vector>
#include "Par.h"
using namespace std;

int main(){
	
	int N = 1000000;

	vector < Par > criba( N + 1 );

	criba[1].setIsPrimo(false);

	for( int i = 2; i <= N; i++ ){
		criba[i].setNumero(i);
	}

	for(int i = 2; i*i <= N; ++i) {
        if(criba[i].isPrimo()) {
            for(int h = 2; i*h <= N; ++h)
                criba[i*h].setIsPrimo(false);
        }
    }

    cout << ( criba[1000000].isPrimo() ? "Es primo" : "No es primo" ) << "\n";
    cout << ( criba[7919].isPrimo() ? "Es primo" : "No es primo" ) << "\n";
    cout << ( criba[2].isPrimo() ? "Es primo" : "No es primo" ) << "\n";
    cout << ( criba[999983].isPrimo() ? "Es primo" : "No es primo" ) << "\n";

	return 0;	
}