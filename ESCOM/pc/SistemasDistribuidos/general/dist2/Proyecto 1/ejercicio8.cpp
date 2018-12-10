#include <iostream>
#include <cmath>

using namespace std;

class Complex{
	friend double addreal(Complex&, Complex&);
	friend double addimag(Complex&, Complex&);
	private:
	    double real;
	    double imag;
	public:
    	Complex(double = 0, double = 0);
    	Complex operator [](double);
    	void display();
};

Complex::Complex(double rl, double im){
	real = rl;
	imag = im;
}

Complex Complex :: operator [](double x){
	Complex temp(real * x, imag * x);
	return temp;
}

void Complex::display(){
	char sign = '+';
	
	if(imag < 0) sign = '-';

	cout << real << sign << abs(imag) << 'i';
	return;
}

double addreal(Complex &a, Complex &b){
	return(a.real + b.real);
}

double addimag(Complex &a, Complex &b){
	return(a.imag + b.imag);
}

int main(){
	Complex a(3.2, 5.6), b(1.1, -8.4);
	double re, im;
	cout << "\nThe first complex number is ";
	a.display();
	cout << "\nThe second complex number is ";
	b.display();
	re = addreal(a,b);
	im = addimag(a,b);
	Complex c(re,im);
	cout << "\n\nThe sum of these two complex numbers is ";
	c.display();
	cout << endl << endl;
	cout << "A = ";
	a.display();
	cout << "\nA with operator[4]: ";
	a = a[4];
	a.display();
	cout << endl;
	return 0;
}	