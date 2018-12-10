#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include <stdlib.h>

using namespace std;

int main(int args, char *argv[]) {
	char *ip   = argv[1];
	int puerto = atoi(argv[2]);
	char *cad  = argv[3];
	int ttl    = atoi(argv[4]);

	SocketMulticast sock(puerto);
	PaqueteDatagrama data(cad, strlen(cad), ip, puerto);
	sock.envia(data, ttl);
	return 0;
}
