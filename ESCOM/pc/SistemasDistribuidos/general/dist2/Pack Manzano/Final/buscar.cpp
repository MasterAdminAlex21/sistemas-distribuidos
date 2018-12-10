#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "Archivo.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
using namespace std;
int main(int argc, char *argv[]){
        vector<int> v;
        vector<string> lib;
        	
        
        Archivo origen(argv[1], O_RDONLY);
	
	v = origen.buscaOcurrencia(argv[1],argv[2]);
	lib = origen.buscaLibros();
	cout << v.size()<<endl;
	cout << lib[5]<<endl;
}	


