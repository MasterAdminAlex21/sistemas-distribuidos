#ifndef GENERADOR_H_
#define GENERADOR_H_
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <cstring>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <ctime>
using namespace std;

struct sms {
	int id;
	int origen;
	string telOrig;
	string telDest;
	string cdOrig;
	string cdDest;
	string fecha;
	string hora;
	char mensaje[165];
};

class Generador
{
public:
	Generador( int n, int edo );
	~Generador();
private:
	void llenaEstados( string* estados );
	string creaTel( int n );
};
#endif