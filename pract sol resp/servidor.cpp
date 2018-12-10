#include "SocketDatagrama.h"
#include <stdlib.h>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    printf("%s\n", "SERVIDOR");
    SocketDatagrama cliente(9000);
    PaqueteDatagrama paquete(50*sizeof(char));
    //int a[2];
    unsigned int num;
    unsigned int aux;
    while(1) {
        printf("\nESPERANDO...");
        printf("\nRECIBIENDO PAQUETE DE: %s:%d", paquete.obtieneDireccion(),paquete.obtienePuerto());
        printf("\nRecibidos = %d\n", cliente.recibe(paquete));
        //memcpy(&num, paquete.obtieneDatos(), 4*sizeof(char));
        //memcpy(&a[1], paquete.obtieneDatos()+(4*sizeof(char)), 4*sizeof(char));
        num=atoi(paquete.obtieneDatos());
        printf("\nRECIBIDO");

        //printf("\n%d + %d", a[0], a[1]);
        //num[0] = a[0] + a[1];
     
        aux = num/9;
        cout<<"\nnum: "<<num<<"\naux: "<<aux<<endl;
        int res;
        for (int i = (8*aux)+1; i < num+1; ++i)
        {
            if(num+1%i==0){
                res++;
            }
        }
        if(res!=2){
            cout<<"es primo"<<endl;
            paquete.inicializaDatos("sii");
        }else{
            cout<<"no es primo"<<endl;
            paquete.inicializaDatos("noo");
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
