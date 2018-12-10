
#include <iostream>
using namespace std;

int main()
{
	/*double c = 20.00;
	double f = ((1.8) * c) + 32.0;*/

	double c = 20;
	double e = (9.0/5.0);
	double f = (e * static_cast<double>(c)) + 32.0;

	cout << f;
	
	return 0;
}