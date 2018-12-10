#include <iostream>
using namespace std;

int main(){
	int N = 20000, cont = 0;
	string cad;
	//srand( time(NULL) );

	for( int i = 0; i < N; i++ ){
		cad += (char)( rand() % 26 ) + 65;
		cad += (char)( rand() % 26 ) + 65;
		cad += (char)( rand() % 26 ) + 65;
		cad += " ";
	}

	int pos = -1;
	while(1){
		pos = cad.find( "IPN", pos+1 );
		if( pos == -1 )
			break;
		cont++;
	}
	//cout << cad<<endl;
	cout << cont << endl;


	return 0;
}