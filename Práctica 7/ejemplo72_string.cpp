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
for (i=1; i<20000;i++){
	Cadenota = Cadenota + Abecedario.at(rand()%25);


	if(i%3==0)
	{
	Cadenota = Cadenota.append(" ");
	}
}

for (j=0; j<19999;j++){
	cout << Cadenota.at(j);
}


  std::size_t found = Cadenota.find(str2);
 if (found!=std::string::npos){
contador +=1;
    std::cout << "Encontramos IPN" << contador << "Veces" << endl;
}
/*
found=Cadenota.find("IPN");
for (Contador   found!=std::string::npos){
	contador=0; ;
	    std::cout << ;

	}
	*/

}
