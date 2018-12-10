#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Palindromo.h"

using namespace std;

bool Palindromo::validacion(string palindromo) {
    string copy = palindromo;
    reverse(copy.begin(), copy.end());
    if(palindromo.compare(copy) == 0)
        return true;
    else
        return false;
}

string Palindromo::lectura(ifstream &archivo, int noPalabras) {
    string resultado = "";
    string aux;
    int pos;
    int i;
    for(i = 0 ; i < noPalabras ; i++) {
        archivo >> aux;
        resultado += aux;
        if(archivo.eof())
            break;
        if(i == 0)
            pos = archivo.tellg();
    }
    if(i != noPalabras)
        resultado = "";
    else
        archivo.seekg(pos, ios_base::beg);
    return resultado;
}