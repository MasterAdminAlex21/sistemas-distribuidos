#include <iostream>
#include <dirent.h>
#include <string.h>
#include "LeerDirectorio.h"

using namespace std;

LeerDirectorio::LeerDirectorio(const string &dir) {
	directorio = dir;
}

vector<string> LeerDirectorio::evaluar() {
	vector<string> archivos;
	
	DIR *dir;
	dir = opendir(directorio.c_str());
	
	if (dir == NULL) {
		cout << "No se pudo abrir el directorio." << endl;
		return archivos;
	}
	
	struct dirent *ent;
	while ((ent = readdir(dir)) != NULL) {
		//std::cout << directorio << std::endl;
		if ((strcmp(ent->d_name, ".") != 0) && (strcmp(ent->d_name, "..") != 0)) {
			//std::cout << "Archivo: " << ent->d_name << std::endl;
			archivos.push_back(std::string(ent->d_name));
		}
	}
	return archivos;	
}
