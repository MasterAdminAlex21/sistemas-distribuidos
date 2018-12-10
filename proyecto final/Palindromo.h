#ifndef PALINDROMO_H
#define PALINDROMO_H

#include <string>
#include <fstream>

using namespace std;

class Palindromo{
    public:
		static bool validacion(string palindromo);
        static string lectura(ifstream &archivo, int noPalabras);
    private:
        Palindromo() {}
};

#endif