#include <stdio.h>
#include <iostream>
#include <string>
#include "Solicitud.h"
#include "mensaje.h"
using namespace std;



int main(int argc, char const *argv[])
{	
	int entrada;
	cout<<"Ingrese el monto a ingresar"<<endl;
	cin>>entrada;
	std::string ip("10.100.70.115"); //mi IP
	std::string ip2("10.100.70.252"); //IP DEL SERVIDOR
	

	mensaje prueba;
	Solicitud cliente;
	int r;
	int t;
	int n=1;
	int q=0;
	while(entrada>0){
		prueba.messageType=89;
		prueba.requestId=entrada;
		memcpy(prueba.IP,(char *)ip.c_str(),16);
		prueba.puerto=7777; //MI PUERTO
		prueba.operationId=1 ;
		memcpy(prueba.arguments,(char*)(&entrada),sizeof(int));

		char *resultado=(char*)malloc(sizeof(TAM_MAX_DATA));

		q=(*(int*)(cliente.doOperation((unsigned char *)ip2.c_str(),7201,prueba.operationId,(char *)&prueba))); //PUERTO DEL SERVIDOR

		prueba.messageType=89;
		prueba.requestId=entrada;
		memcpy(prueba.IP,(char *)ip.c_str(),16);
		prueba.puerto=7777; //MI PUERTO
		prueba.operationId=2 ;
		memcpy(prueba.arguments,(char*)(&n),sizeof(int));

		


		r=(*(int*)(cliente.doOperation((unsigned char *)ip2.c_str(),7201,prueba.operationId,(char *)&prueba))); //PUERTO DEL SERVIDOR
		
		cout<<"Antes tenia usted $"<<q<<" ahora tiene $"<<r<<endl;
		/*if(q!=r-1){
			puts(resultado);
			cout<<"Hubo un error!!"<<endl;
			return 0;
		}
		cout<<r<<endl;*/

		entrada--;
	}

	

	


	
	return 0;
}
