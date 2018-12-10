#include <iostream>
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	double x , r , t;
	cout << "DAME EL NUMERO PARA SACAR LA RAIZ\n";
	cin >> x;
	r = x;
	t = 0;
	while( t != r )
	{
		t = r;
		r = ( x/r + r)/2;
	}
	cout << r<<endl;

	return 0;
}
