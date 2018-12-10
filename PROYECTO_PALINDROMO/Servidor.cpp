#include "Respuesta.h"
#include "Palindromo.h"
#include "respuesta.h"
#include "archivo.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <algorithm>
//#include "Servidor.h"

using namespace std;

int validacion(string palindromo) {
    string copy = palindromo;
    reverse(copy.begin(), copy.end());
    if(palindromo.compare(copy) == 0)
        return 1;
    else
        return 0;
}

int main(int argc,char** argv)
{
	int nbd=0;
	Respuesta servidor(1234);
	mensaje* msj=NULL;
	char *id=NULL;
	respuesta resp;
    int idProcesada=0;


	cout<<"Servidor iniciado . . . esperando datagramas"<<endl;
	while(1){

		msj= servidor.getRequest();

			if (msj != NULL){
				 idProcesada++;


				if(idProcesada == msj->requestId){
					cout<<msj->requestId<<endl;
					cout<<"Cadena: "<<msj->arguments<<endl;

				     resp.id = msj->requestId;
				     
				     resp.r  = validacion(msj->arguments);  
				    
				     cout<<"Respuesta a enviar"<<resp.r<<endl;
					
				}
					
				else {
					cout << "Mensaje duplicado, accion ignorada" << endl;
					idProcesada--;
				}

				char* copy=(char*)malloc(sizeof(respuesta));
			    memcpy(copy,&resp,sizeof(respuesta));
				servidor.sendReply(copy,msj->IP,msj->puerto,msj->requestId);

			}

		}
	  
	return 1;
}