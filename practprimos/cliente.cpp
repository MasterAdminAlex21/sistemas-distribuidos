#include<iostream>
#include<string.h>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;

int main(int argc, char *argv[]){
 if(argc!=2){
  printf("uso: %s numero\n",argv[0]);
  exit(0);
 }

 //unsigned int numero=atoi(argv[1]);
 PaqueteDatagrama *p1;
 p1=new PaqueteDatagrama(argv[1],strlen(argv[1]),/*aqui la direccion de un server*/,9000);
 SocketDatagrama *s;
 s=new SocketDatagrama(0);
 s->envia(p1);
 p1->inicializaIP(/*aqui la otra direccion*/);
 s->envia(p1);
 s->recibe(p1);
 char *res1,*res2;
 res1=p1.obtieneDatos();
 s->recibe(p1);
 res2=p1.obtieneDatos();

 if(strcmp(res1,"si")==0 && strcmp(res2,"si"))
  printf("es primo\n");
 else 
  printf("no es primo\n");
}