#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> // inet_ntoa()
#include <netinet/in.h> // ntohs()
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>

using namespace std;
struct messageSC
{
	char nombre[45];
	uint32_t num[10];
};
int puerto = 7300;

int main(void) 
{
   	char msj[50], msj_cliente[50];

   	SocketDatagrama servidor(puerto);
   	PaqueteDatagrama pk_recv(sizeof(msj));
   
   	cout << "Iniciando Servidor..."<<endl;

   	while(1) 
  	{
		int n= servidor.recibe(pk_recv);
		char *ip_cliente= pk_recv.obtieneDireccion();
		int pto_cliente= pk_recv.obtienePuerto();
		cout << "Mensaje recibido de cliente "<<ip_cliente<<":"<<pto_cliente<<endl;
		char *datos=pk_recv.obtieneDatos();
    	int* arreglo=(int*)datos;
      printf("Recibido ");
       for (int i = 0; i < 10; ++i)
       {
        printf("%d\n",arreglo[i]);
       }
    	  
    	struct messageSC mens;
    	strcpy(mens.nombre,"Jimenez Romero Hector Ivan ");
    	for (int i = 0; i < 10; ++i)
      {
        for (int j = 0; j<10-i; ++j)
        {
          if(arreglo[j]>arreglo[j+1]){
            int aux=arreglo[j+1];
            arreglo[j+1]=arreglo[j];
            arreglo[j]=aux;
          }
        }
      }
      printf("Enviados\n");
      for (int i = 0; i < 11; ++i)
      {
        printf("%d \n",arreglo[i]);
      }
      for (int i = 1; i < 11; ++i)
      {
        mens.num[i-1]=arreglo[i];
      }
    

      PaqueteDatagrama pk_send((char*)&mens, sizeof(mens), ip_cliente, pto_cliente);  
    cout << "Enviando" << endl;
    int m=servidor.envia(pk_send);
    }
  return 0;
}

