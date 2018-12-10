#include "Solicitud.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc!=4){
        cout<<"./Cliente <IP> <PUERTO> <CANTIDAD>" << endl;
        cout << "Asegurese de que haya ingresado mediante comandos los parametros requeridos" << endl;
        return -1;
    }

    Solicitud cliente;
    cout<<"CLIENTE"<<endl;
    cout<<"ENVIANDO PAQUETE A " << argv[1]<<" : "<< atoi(argv[2]) <<endl;

    char sol[]={'2','1'};
    for(int i=0;i<atoi(argv[3]);i++){
        char * respuesta = cliente.doOperation(argv[1], atoi(argv[2]), 1, sol );
        //cout<<"Cadena enviada" << endl;
        cout<<"MENSAJE RECIBIDO: " << argv[1]<<" : "<< atoi(argv[2]) << endl;
        cout<<"Respuesta saldo: " << atoi(respuesta) << endl;
    }
    return 0;
}
