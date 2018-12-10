#include <iostream>
#include <stdlib.h>

using namespace std;


class Circle{
	private:
		int xCenter;
		int yCenter;
		double radius;
		static double scaleFactor;
	public:
		Circle(int = 0, int = 0, double = 0.0);
		void showCircle();
		void setScale(double);
};

double Circle :: scaleFactor = 1.0;

Circle :: Circle(int x, int y, double r){
	xCenter = x;
	yCenter = y;
	radius = r;
}

void Circle :: setScale(double s){
	scaleFactor = s;
}

void Circle :: showCircle(){
	cout << "The center of the circle: (" << xCenter << ", " << yCenter << ")\n";
	cout << "The radius of the circle: " << radius * scaleFactor << endl << endl;
}

int main(){
	Circle a;
	Circle b(10, 5, 3.0);
	Circle c(1, 1, 1.0);

	a.showCircle();
	b.showCircle();
	c.showCircle();

	a.setScale(2.0);
	a.showCircle();
	b.showCircle();
	c.showCircle();

	b.setScale(.9381928391);
	a.showCircle();
	b.showCircle();
	c.showCircle();
	
	return 0;
}