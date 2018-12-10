#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include<cstring>
using namespace std;

class Archivo{
private:
 string nombreArchivo;
 int fd;
 char *contenido;
 size_t num_bytes;
public:
 Archivo(string filename);
 Archivo(string filename, int banderas, mode_t modo);
 size_t lee(size_t nbytes);
 size_t escribe(void *buffer, size_t nbytes);
 size_t obtieneNum_bytes();
 const char* get_contenido();
 ~Archivo();
};

Archivo::Archivo(string filename){
 nombreArchivo=filename;
 /*char filen[nombreArchivo.size()];
 strcpy(filen,nombreArchivo);*/
 fd=open(nombreArchivo.c_str(),O_RDONLY);
 if(fd==-1){
  cout<<"Error al abrir el fichero"<<endl;
  exit(0);
 }
  contenido=(char*)malloc(sizeof(char));
  num_bytes=0;
}

Archivo::Archivo(string filename,int banderas, mode_t modo){
 nombreArchivo=filename;
 /*char filen[nombreArchivo.size()];
 strcpy(filen,nombreArchivo);*/
 fd=open(nombreArchivo.c_str(),banderas,modo);
 if(fd==-1){
  cout<<"Error al abrir el archivo"<<endl;
  exit(0);
  }
  contenido=(char*)malloc(sizeof(char)*1);
}

size_t Archivo::lee(size_t nbytes){
 size_t aux;
 contenido=(char*)realloc(contenido,num_bytes+nbytes);
 aux=read(fd,contenido+num_bytes,nbytes);
 num_bytes+=aux;
 return aux;
}

size_t Archivo::escribe(void *buffer, size_t nbytes){
  size_t aux=write(fd,buffer,nbytes);
  return aux;
}

size_t Archivo::obtieneNum_bytes(){
 return num_bytes;
}

const char* Archivo::get_contenido(){
 return contenido;
}

Archivo::~Archivo(){
 close(fd);
 free(contenido);
}


int main(int argc, char* argv[])
{
 if(argc!=3){
  cout<<"forma de uso: "<<argv[0]<<" archivo origen archivo destino"<<endl;
  exit(0);
 }
 Archivo *origen;
 origen=new Archivo(argv[1]);
 Archivo *destino;
 destino=new Archivo(argv[2],O_TRUNC|O_CREAT|O_WRONLY,0666);

 const char *buffer;
 //buffer=origen->get_contenido();

 while(origen->lee(BUFSIZ)>0);
 buffer=origen->get_contenido();
 //cout<<"contenido: "<<buffer<<endl;
 cout<<origen->obtieneNum_bytes()<<endl;
 destino->escribe((void *)buffer,origen->obtieneNum_bytes());
 delete origen;
 delete destino;
 
}