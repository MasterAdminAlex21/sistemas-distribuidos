
#include <stdio.h>
#include <unistd.h>
#include "SocketDatagrama.h"
#include "mensaje.h"


using namespace std;

class Respuesta{
	public:
	 Respuesta(int pl);
	 struct mensaje *getRequest(void);
	 void sendReply(char *respuesta, unsigned char *ipCliente, int puertoCliente, int Longitud);
	private:
	 SocketDatagrama *sockt;
};


