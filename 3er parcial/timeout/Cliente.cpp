#include "Solicitud.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc<3){
        cout<<"./Cliente <IP> <PUERTO>" << endl;
        cout << "Asegurese de que haya ingresado mediante comandos los parametros requeridos" << endl;
        return -1;
    }

    Solicitud cliente;
    cout<<"CLIENTE"<<endl;
    cout<<"ENVIANDO PAQUETE A " << argv[1]<<" : "<< atoi(argv[2]) <<endl;
    char cadena[] = "Prueba cliente servidor - inversion de cadenas";
    cout<<"Contenido de la cadena: "<< cadena << endl;
    char * respuesta = cliente.doOperation(argv[1], atoi(argv[2]), 1, cadena);
    //cout<<"Cadena enviada" << endl;
    cout<<"MENSAJE RECIBIDO: " << argv[1]<<" : "<< atoi(argv[2]) << endl;
    cout<<"Respuesta cadena invertida: " << respuesta << endl;

    return 0;
}
