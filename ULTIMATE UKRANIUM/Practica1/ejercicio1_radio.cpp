
#include <iostream>
using namespace std;

int main()
{
	const double PI = 3.1415926;
	double pi = 3.1415962;
	double radio = 0;
	double area = 0;

	cout << "Radio del circulo: ";

	cin >> radio;

	if (radio > 0) {
		area = PI * (radio*radio);
		cout << "Area: " << area;
	}
	else
		cout << "El circulo no tiene area :(";

	return 0;
}