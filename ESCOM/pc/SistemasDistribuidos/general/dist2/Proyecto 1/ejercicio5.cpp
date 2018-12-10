#include <iostream>
#include <stdlib.h>

using namespace std;


class Fractions{
	private:
		int num;
		int denum;
	public:
		Fractions(int = 0, int = 1);
		Fractions(const Fractions&);
		void setValues(int, int);
		void showFractions();
		Fractions operator + (Fractions&);
		Fractions operator - (Fractions&);
		Fractions operator / (Fractions&);
		Fractions operator * (Fractions&);

};

Fractions :: Fractions(int x, int y){
	num = x;
	denum = y;
}

void Fractions :: showFractions(){
	cout << num << "/" << denum << endl << endl;
}

Fractions :: Fractions(const Fractions& aux){
	num = aux.num;
	denum = aux.denum;	
}

void Fractions :: setValues(int x, int y){
	num = x;
	denum = y;
}

Fractions Fractions :: operator + (Fractions& op1){
	Fractions temp;
	temp.num = num * op1.denum + denum * op1.num;
	temp.denum = denum * op1.denum;
	return temp;
}

Fractions Fractions :: operator - (Fractions& op1){
	Fractions temp;
	temp.num = num * op1.denum - denum * op1.num;
	temp.denum = denum * op1.denum;
	return temp;
}

Fractions Fractions :: operator / (Fractions& op1){
	Fractions temp;
	temp.num = num * op1.denum;
	temp.denum = denum * op1.num;
	return temp;
}

Fractions Fractions :: operator * (Fractions& op1){
	Fractions temp;
	temp.num = num * op1.num;
	temp.denum = denum * op1.denum;
	return temp;
}





int main(){
	Fractions a(5, 3), b(7, 5), c;

	cout << "A = ";
	a.showFractions();
	cout << "B = ";
	b.showFractions();

	cout << "Sum A + B = ";
	c = a + b;
	c.showFractions();

	cout << "Sum A - B = ";
	c = a - b;
	c.showFractions();

	cout << "Sum A * B = ";
	c = a * b;
	c.showFractions();

	cout << "Sum A / B = ";
	c = a / b;
	c.showFractions();

}