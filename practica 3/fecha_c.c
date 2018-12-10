#include<stdio.h>
#include<stdlib.h>
#include "fecha_c.h"
#include<time.h>

fecha creafecha(int,int,int);
int masVieja(fecha fecha1,fecha fecha2);
int masvieja(fecha *fecha1,fecha *fecha2);

int main(){
 srand(time(NULL));

 int dia,mes,anio,n;

 fecha f1,f2;
 //printf("ingrese n: ");
// scanf("%d",&n);

 for(int i=0;i<100000;i++){
  dia=rand()%(31-1)+1;
  mes=rand()%(12-1)+1;
  anio=rand()%2019;
  //printf("fecha 1: %d %d %d\t",dia,mes,anio);
  f1=creafecha(dia,mes,anio);
  //printf("fecha 1: %d %d %d\n",f1->dia,f1->mes,f1->anio);
  dia=rand()%31 +1;
  mes=rand()%12 +1;
  anio=rand()%2019;
  //printf("fecha 1: %d %d %d\t",dia,mes,anio);
  f2=creafecha(dia,mes,anio);
  //printf("fecha 2: %d %d %d\n",f2->dia,f2->mes,f2->anio);

  //printf("valor arrojado con paso por copia: %d\n",
  //masVieja(f1,f2);
  
  masvieja(&f1,&f2);
 }

}

fecha creafecha(int d, int m, int a){
 if(d<32 && d>0){
  if(m<13 && m>0){
   if(a>-1 && a<2020){
    fecha f=(fecha)malloc(sizeof(Fecha));
     if(f==NULL){
      printf("Error: no hay memoria\n");
      exit(0);
     }
     f->dia=d;
     f->mes=m;
     f->anio=a;
     return f;
   }else{
    printf("año incorrecto\n");
    return NULL;
   }
  }else{
   printf("mes incorrecto\n");
   return NULL;
  }
 }else{
  printf("Dia no valido\n");
  return NULL;
 }
 return NULL;
}

int masVieja(fecha fecha1,fecha fecha2){
 if(fecha1->anio>fecha2->anio){
  return 1;
 }else if(fecha1->anio==fecha2->anio){
  if(fecha1->mes>fecha2->mes){
   return 1;
  }else if(fecha1->mes==fecha2->mes){
   if(fecha1->dia>fecha2->dia){
    return 1;
   }else if(fecha1->dia==fecha2->dia){
    return 0;
   }else return -1;
  }else return -1;
 }else return -1;
}

int masvieja(fecha *fecha1,fecha *fecha2){
 if((*fecha1)->anio>(*fecha2)->anio){
  return 1;
 }else if((*fecha1)->anio==(*fecha2)->anio){
  if((*fecha1)->mes>(*fecha2)->mes){
   return 1;
  }else if((*fecha1)->mes==(*fecha2)->mes){
   if((*fecha1)->dia>(*fecha2)->dia){
    return 1;
   }else if((*fecha1)->dia==(*fecha2)->dia){
    return 0;
   }else return -1;
  }else return -1;
 }else return -1;
}
