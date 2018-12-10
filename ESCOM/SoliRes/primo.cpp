#include <iostream>

using namespace std;
int main(){
unsigned int d;
bool primo=true;
cout<<"Ingrese el numero"<<endl;
cin>>d;
int i=2;
	while(primo==true && i<d){
	if(d%i==0){
	primo=false;
	}
	i++;
	}

	if(primo){
	cout<<"El numero "<<d<<" es primo"<<"\n";
	}
	else{
	cout<<"El numero "<<d<<" no es primo"<<"\n";
	}
	
}
