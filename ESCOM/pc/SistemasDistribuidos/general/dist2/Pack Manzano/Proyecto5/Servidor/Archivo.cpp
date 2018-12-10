#include "Archivo.h"
using namespace std;

Archivo::Archivo(const char *filename, int banderas){
	nombreArchivo = filename;
	if((fd = open(filename, banderas)) == -1){
		perror(filename);
		exit(-1);
   	}
}
Archivo::Archivo(const char *filename, int banderas, mode_t modo){
	nombreArchivo = filename;
	if((fd = open(filename, banderas, modo)) == -1){
		perror(filename);
		exit(-1);
	}
}

Archivo::~Archivo(){
}

size_t Archivo::lee(size_t nbytes){
	contenido = new char[nbytes+5];
	return read(fd, contenido, nbytes);
}

size_t Archivo::escribe(const void *buffer, size_t nbytes){
	return write(fd, buffer, nbytes);
}
char *Archivo::get_contenido(){
	return contenido;
}
void Archivo::cerrar(){
	close(fd);
}