#ifndef ARCHIVO_H_
#define ARCHIVO_H_
#include <cstring>
#include <string>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <new>
#include <sys/types.h>
#include <dirent.h>
using namespace std;

class Archivo
{
public:
	Archivo(const char *filename, int banderas);
	Archivo(const char *filename, int banderas, mode_t modo);
	~Archivo();
	size_t lee(size_t nbytes);
	size_t escribe(const void *buffer, size_t nbytes);
	char *get_contenido();
	vector<int> buscaOcurrencia(char* archivo, char* cadena);
	vector<string> buscaLibros();
	void cerrar();
protected:
	string nombreArchivo; //Almacena el nombre del archivo
	int fd; //Almacena el descriptor de archivo
	char *contenido; //Almacena temporalmente contenido parcial o total del archivo
};
#endif
