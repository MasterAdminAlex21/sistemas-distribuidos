#include <iostream>
#include <cmath>
using namespace std;

// class declaration section
class Complex
{
  // friends list
  friend double addreal(Complex&, Complex&);
  friend double addimag(Complex&, Complex&);
  private:
    double real;
    double imag;
  public:
    Complex(double = 0, double = 0);  // constructor
    void display();
    Complex operator[](int);
};
// class implementation section
Complex::Complex(double rl, double im)
{
  real = rl;
  imag = im;
}
void Complex::display()
{
  char sign = '+';
  if(imag < 0) sign = '-';
  cout << real << sign << abs(imag) << 'i';
  return;
}
// friend implementations
double addreal(Complex &a, Complex &b)
{
  return(a.real + b.real);
}

double addimag(Complex &a, Complex &b)
{
  return(a.imag + b.imag);
}

Complex Complex::operator[](int factor){
	return Complex( factor * real , factor * imag );
}

int main()
{
  Complex a(3.2, 5.6), b(1, 2);
  (a[2]).display();
  cout <<"\n";
  ( b[5] ).display();
  cout << "\n";

  return 0;
}