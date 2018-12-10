#include "SocketDatagrama.h"

int puerto = 7200;
int tam = 1000;

int main(){
	SocketDatagrama sock(0);
	int *num = new int[2];
	num[0] = 1;
	num[1] = 919;
	char ip[16];
	sock.setBroadcast();
	sprintf(ip, "192.168.0.255");
   	PaqueteDatagrama paks((char *)num, 8, ip, puerto);
   	sock.envia(paks);
   	PaqueteDatagrama rev(4);
   	sock.recibe(rev);
}

