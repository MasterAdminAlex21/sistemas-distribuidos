#include "SocketDatagrama.h"
#include <stdlib.h>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(9000);
    PaqueteDatagrama paquete(sizeof(unsigned int));
    //int a[2];
    unsigned int num;
    unsigned int aux;
    while(1) {
        printf("\nESPERANDO...");
        printf("\nRECIBIENDO PAQUETE DE: %s:%d", paquete.obtieneDireccion(),paquete.obtienePuerto());
        printf("\nRecibidos = %d\n", cliente.recibe(paquete));
        memcpy(&num, paquete.obtieneDatos(), 4*sizeof(char));
        //memcpy(&a[1], paquete.obtieneDatos()+(4*sizeof(char)), 4*sizeof(char));
        printf("\nRECIBIDO");

        //printf("\n%d + %d", a[0], a[1]);
        //num[0] = a[0] + a[1];
     
        aux = num/2;
        int res;
        for (int i = 1; i < (aux+1); ++i)
        {
            if(aux%i==0){
                res++;
            }
        }
        if(res!=2){
            cout<<"es primo"<<endl;
            paquete.inicializaDatos("si");
        }else{
            cout<<"no es primo"<<endl;
            paquete.inicializaDatos("no");
        }
        
        
        printf("\nENVIANDO PAQUETE...");
        paquete.inicializaPuerto(paquete.obtienePuerto());
        paquete.inicializaIp(paquete.obtieneDireccion());
        //paquete.inicializaDatos((char *)num);
        cliente.envia(paquete);
        printf("\nPAQUETE ENVIADO");
    }
    return 0;
}
