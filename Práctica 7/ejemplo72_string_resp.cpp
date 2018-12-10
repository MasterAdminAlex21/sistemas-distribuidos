#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

int main() 
{
srand(time(NULL));
//  Comienza Ejercicio 3
string Abecedario("ABCDEFGHIJKLMNOPQRSTUVWXYZ"); // 0-25
string Cadenota ("");
std::string str2 ("IPN");
int i,j,contador=0;
for (i=1; i<100000;i++){
	Cadenota = Cadenota + Abecedario.at(rand()%25);


	if(i%3==0)
	{
	Cadenota = Cadenota.append(" ");
	}
}

for (j=0; j<99999;j++){
	cout << Cadenota.at(j);
}//


  std::size_t found=0;// = Cadenota.find(str2);
j=0;
while(found<Cadenota.length()){
//cout<<"entro al while"<<endl;
 found=Cadenota.find(str2,(found+1));
 if(found!=std::string::npos){
  contador+=1;
 }
j+=1;
//cout<<j<<" ";
}

cout<<"numero de veces: "<< contador << endl;

/*
found=Cadenota.find("IPN");
for (Contador   found!=std::string::npos){
	contador=0; ;
	    std::cout << ;

	}
	*/

}
