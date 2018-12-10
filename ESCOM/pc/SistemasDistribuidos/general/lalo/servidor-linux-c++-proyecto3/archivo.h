#ifndef ARCHIVO
#define ARCHIVO

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

class Archivo {

public:
	Archivo(const string&);
	void division_tokens(vector<string>&);
	pair< vector<int>, int> maxima_coincidencia(Archivo b);
	string getNombre();
private:
	string nombre, contenido;
};

#endif