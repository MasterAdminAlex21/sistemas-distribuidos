#include <stdio.h>
#include <iostream>
#include <string>
#include "Respuesta.h"
#include <string.h>
#include <stack>

using namespace std;


int main(int argc, char const *argv[])
{	
	//int* array=(int*)malloc(sizeof(int)*2);


	Respuesta resp(7201);
	mensaje *prueba=(mensaje*)malloc(sizeof(mensaje));
  	int nbd=0;
	while (true){
		prueba=resp.getRequest();
		if(prueba->operationId==1){
		 	string s=to_string(nbd);
		    cout<<"verifico saldo"<<endl;
			resp.sendReply((char*) &nbd, (unsigned char *)prueba->IP,prueba->puerto, sizeof(nbd));

		}
		else if(prueba->operationId==2){
			nbd+=(*(int *) prueba->arguments);
			string s=to_string(nbd);
			 cout<<"modifico el saldo a --------------- "<<nbd<<" voy a enviar :  "<<s<<endl;

			resp.sendReply((char*) &nbd, (unsigned char *)prueba->IP,prueba->puerto, sizeof(nbd));
		}

	}
	

	

	




	
	return 0;
}
