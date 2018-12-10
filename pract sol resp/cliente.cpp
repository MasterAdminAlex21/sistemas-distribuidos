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
 //4294967291

 //unsigned int numero=atoi(argv[1]);
 PaqueteDatagrama *p1,*p2,*p3,*p4;
 p1=new PaqueteDatagrama(argv[1],strlen(argv[1]),"10.100.78.22"/*aqui la direccion de un server*/,9000);
 p2=new PaqueteDatagrama(2*sizeof(char));
 p3=new PaqueteDatagrama(2*sizeof(char));
 p4=new PaqueteDatagrama(2*sizeof(char));

 SocketDatagrama *s;
 s=new SocketDatagrama(0);
 s->envia(*p1);
 p1->inicializaIp("10.100.70.252"/*aqui la otra direccion*/);
 s->envia(*p1);
 p1->inicializaIp("10.100.71.6");//una ip mas
 s->envia(*p1);
 s->recibe(*p2);
 char *res1,*res2,*res3;


 res1=p2->obtieneDatos();
 cout<<"datos de p2 "<<p2->obtieneDatos()<<endl;
 s->recibe(*p3);
 res2=p3->obtieneDatos();
 cout<<"datos de p3 "<<p3->obtieneDatos()<<endl;

 s->recibe(*p4);
 res3=p4->obtieneDatos();


 printf("res1: %s  \t res2: %s\t res3: %s\n",res1,res2,res3 );

 if(strcmp(res1,"si")==0 && strcmp(res2,"si")==0 && strcmp(res3,"si")==0)
  printf("es primo\n");
 else 
  printf("no es primo\n");
}