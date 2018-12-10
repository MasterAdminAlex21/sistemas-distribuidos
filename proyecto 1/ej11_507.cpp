#include<iostream>
using namespace std;

class Fractions{
public:
  int num;
 int den;
 Fractions(int = 1,int =1);
 Fractions operator+(Fractions&);
 Fractions operator-(Fractions&);
 Fractions operator*(Fractions&);
 Fractions operator/(Fractions&);
 void show();
};

//implementation

Fractions::Fractions(int nume,int deno){
 if(nume==0){ 
  num=1;
 }else{
  num=nume;
 }
 if(deno==0){
  den=1;
 }else{
  den=deno;
 }
}

Fractions operator+(Fractions& add){
 Fractions adder;
 adder.num=(num*add.den)+(den*add.num);
 adder.den=den*add.den;
 return adder;
}

Fractions operator-(Fractions& sub){
 Fractions substract;
 substract.num=(num*sub.den)-(sub*add.num);
 substract.den=d1en*sub.den;
 return substract;
}

Fractions operator*(Fractions& mul){
 Fractions multiplier;
 multiplier.num=num*mul.num;
 multiplier.den=den*mul.den;
 return multiplier;
}

Fractions operator/(Fractions& div){
 Fractions divider;
 divider.num=num*div.den;
 divider.den=den*div.num;
 return divider;
}

void Fractions::show(){
 cout<<"value: "<<num<<"/"<<den<<endl;
}

int main(){
 Fractions a(3,2),b(6,8),add,subs,mult,div;
 cout<<"fraction a "<<endl;
 a.show();
 cout<<"fraction b"<<endl;
 b.show();
 add=a+b;
 subs=a-b;
 mult=a*b;
 div=a/b;
 cout<<"addition "<<endl;
 add.show();
 cout<<"substraction"<<endl;
 subs.show();
 cout<<"multiplication"<<endl;
 mult.show();
 cout<<"division"<<endl;
 div.show();

}