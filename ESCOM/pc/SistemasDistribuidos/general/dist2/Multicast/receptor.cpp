#include "SocketMulticast.h"
#include <stdlib.h>

using namespace std;

int main(int args, char *argv[]) {
	char *ip   = argv[1];
	int puerto = atoi(argv[2]);

	SocketMulticast sock(puerto);
	PaqueteDatagrama data(1000);
	sock.recibe(data, ip);
	cout << data.obtieneDatos() << endl;
	return 0;
}