#include <iostream>
using namespace std;

int main(){
	int N = 100000, cont = 0;
	srand( time(NULL) );

	char *cad = malloc( sizeof(char) * ( ( N * 4 ) + 1 ) );

	for( int i = 0; i < N*4; i++ ){
		if( i % 4 == 0 ){
			cad[i] = ' ';
		}
		else{
			cad[i] = (char)( rand() % 26 ) + 65;
		}
	}

	for( int i = 0; i < N; i+=4 ){
		if( cad[i] == 'I' && cad[i+1] == 'P' && cad[i+2] == 'N' )
			cont++;
	}

	cout << cont << endl;


	return 0;
}