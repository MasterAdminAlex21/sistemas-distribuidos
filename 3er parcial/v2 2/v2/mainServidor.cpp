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
	mensaje respuesta;
  	int nbd=0;
	int messageTypePasado=1;

	respuesta.messageType=prueba->messageType;
	respuesta.requestId=prueba->requestId;
	memcpy(respuesta.IP,(char *)prueba->IP,16);
	respuesta.puerto=prueba->puerto; //MI PUERTO
	respuesta.operationId=2 ;
	



	while (true){
		prueba=resp.getRequest();
		if(prueba->operationId==1){
		 	string s=to_string(nbd);
		    cout<<"verifico saldo"<<endl;
		    memcpy(respuesta.arguments,(char*)(&nbd),sizeof(nbd));
			resp.sendReply((char*) &respuesta, (unsigned char *)prueba->IP,prueba->puerto, sizeof(respuesta));

		}
		else if(prueba->operationId==2){
			if(prueba->messageType==messageTypePasado){
				cout<<"El operation id es: "<<prueba->messageType<<endl;
				nbd+=(*(int *) prueba->arguments);
				string s=to_string(nbd);
			 	cout<<"modifico el saldo a --------------- "<<nbd<<" voy a enviar :  "<<s<<endl;
			 	 memcpy(respuesta.arguments,(char*)(&nbd),sizeof(nbd));
			 	 resp.sendReply((char*) &respuesta, (unsigned char *)prueba->IP,prueba->puerto, sizeof(respuesta));
				messageTypePasado++;
			}
			else{
				int error=-1;
				cout<<"El opetaion id es: "<<prueba->messageType<<endl;
				 memcpy(respuesta.arguments,(char*)(&error),sizeof(error));
				 resp.sendReply((char*) &respuesta, (unsigned char *)prueba->IP,prueba->puerto, sizeof(respuesta));
			}
		}

	}
	

	

	




	
	return 0;
}
