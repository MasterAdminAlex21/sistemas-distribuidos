#include <stdio.h>
#include <unistd.h>
#include "SocketDatagrama.h"


using namespace std;


class Solicitud
{
public:
	Solicitud();
	char * doOperation( unsigned char *IP, int puerto, int operationId, char* argumentos);
private:
	SocketDatagrama *sockt;
};

