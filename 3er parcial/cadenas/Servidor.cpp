#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "SocketDatagrama.h"
#include "Mensaje.h"
#include "Respuesta.h"

#define TAM 200
char cadena2[TAM];
using namespace std;

void invertir(char cadena[]){
    int cont=0;
    memset(cadena2,'\0',TAM);
    int tam=strlen(cadena);
    int aux;
    for(tam; tam>=0; tam--){
        if(cadena[tam]==' '){
            aux = tam+1;
            while(cadena[aux] !=' '  ){
                if(aux==strlen(cadena))
                    break;
                cadena2[cont++]=cadena[aux];
                aux++;
            }
            cadena2[cont++]=' ';
        }
        if(tam==0){
            aux = tam;
            while(cadena[aux] !=' '){
                cadena2[cont++]=cadena[aux];
                aux++;
            }

        }
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
        cout<<"RECIBIENDO MENSAJE: " << cadenaRecibida << endl;
        longitudCadena = cadenaRecibida.length();
        cout<<"TAMAÑO DE LA CADENA: " << longitudCadena << endl;

        char* cadena = new char[longitudCadena + 1];
        strcpy(cadena,cadenaRecibida.c_str());
        cout<<"Invirtiendo la cadena" << endl;
        invertir(cadena);
        string cadenaInvertida(cadena2);
        cout<<"Contenido de la cadena: "<< cadenaInvertida << endl;
        cout<<"Enviando cadena" << endl;
        respuesta.sendReply((char *)cadenaInvertida.c_str(), msg->IP, msg->puerto);
        cout<<"Cadena enviada" << endl;

    }

}
