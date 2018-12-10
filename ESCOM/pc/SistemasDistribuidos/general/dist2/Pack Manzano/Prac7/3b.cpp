#include <iostream>
using namespace std;

int main(){
	int N = 20000, cont = 0;
	char *cad = NULL;

	//srand( time(NULL) );

	for( int i = 0; i < N*4; i+= 4 ){
		cad = (char*)realloc(cad, i+4);
		cad[ i ] = (char)( rand() % 26 ) + 65;
		cad[ i+1 ] = (char)( rand() % 26 ) + 65;
		cad[ i+2 ] = (char)( rand() % 26 ) + 65;
		cad[ i+3 ] = ' ';
	}

	for( int i = 0; i+2 < N*4; i+=4 ){ 
		if( cad[i] == 'I' && (char)cad[i+1] == 'P' && (char)cad[i+2] == 'N' )
			cont++;
	}
	//string aux = cad;
	//cout << cad<<endl;
	cout << cont <<endl;


	return 0;
}