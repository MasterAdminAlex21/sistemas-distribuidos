#include "SocketDatagrama.h"

int puerto = 7200;
int tam = 1000;

int main(){
	SocketDatagrama sock(0);
	int *num = new int[2];
	num[0] = 1;
	num[1] = 919;
	char ip[16];
	pid_t pid;
	for(int i = 0; i < 154; i++){
		pid = fork();
		if(pid != 0)
			break;
	}
	sprintf(ip, "192.168.0.%d", i + 100);
   	PaqueteDatagrama paks((char *)num, 8, ip, puerto);
   	sock.envia(paks);
   	PaqueteDatagrama rev(4);
   	sock.recibe(rev);
}

