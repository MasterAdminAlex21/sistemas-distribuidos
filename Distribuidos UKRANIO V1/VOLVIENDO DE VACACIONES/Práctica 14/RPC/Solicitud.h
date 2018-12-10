
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
using namespace std;

class Solicitud 
{
	public:
		Solicitud();
		char * doOperation(char *IP, int puerto, int operationId, char *arguments);
	private:
		SocketDatagrama *socketlocal;
};
