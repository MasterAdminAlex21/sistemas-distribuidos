#include <iostream>

using namespace std;

class Circle
{
private:
 int xCenter;
 int yCenter;
 double radius;
 int scaleFactor;
public:
 Circle(int=0,int=0,double=1.0,int=1);
 void display();
};

//implementation

Circle::Circle(int x, int y, double rad,int scale){
 xCenter=x;
 yCenter=y;
 radius=rad;
 scaleFactor=scale;
}

void Circle::display(){
 cout<<"Central coordinate (x,y): ("<<xCenter<<","<<yCenter<<")\nRadius: "<<radius<<endl;
 cout<<"Radius scaled: "<<scaleFactor*radius<<endl;
}

int main(){
 Circle a(3,2,5.0,3),b(0,0,3.56,12),c;
 a.display();
 b.display();
 c.display();
}