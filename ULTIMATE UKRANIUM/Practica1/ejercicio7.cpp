
#include <iostream>
using namespace std;

int main()
{
	double precio = 78.7;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(5);
	cout << precio;
	
	return 0;
}