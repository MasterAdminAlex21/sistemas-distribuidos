#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.h"

#define TAM 200
char cadena2[TAM];
int cuenta=0;
using namespace std;

void banco(int op,int inc){
    if(op==1){
        //return cuenta;
    }else if(op==2){
        cuenta+=inc;
        
    }
}

int main(int argc, char*argv[]) {
    int longitudCadena = 0;
    int contador = 0;
    int i = 0;
    int j = 0;
    Respuesta respuesta(7200);

    while(true) {
        cout<<"ESPERANDO..."<<endl;
        struct mensaje *msg = respuesta.getRequest();
        string cadenaRecibida = msg->arguments;
        int longitud=cadenaRecibida.length();

        int ope=atoi(cadenaRecibida.substr(0,1).c_str());
        int cant=atoi(cadenaRecibida.substr(1).c_str());
        cout<<"RECIBIENDO MENSAJE: " << cadenaRecibida << endl;
        
        banco(ope,cant);

        cout<<"Enviando cadena" << endl;
        //for(int i=0;i<7;i++){
        string num=to_string(cuenta);
        cout<<"saldo "<<num.c_str()<<endl;
            respuesta.sendReply((char*)num.c_str(), msg->IP, msg->puerto);
         //   sleep(1);
       // }
        cout<<"Cadena enviada" << endl;

    }

}
