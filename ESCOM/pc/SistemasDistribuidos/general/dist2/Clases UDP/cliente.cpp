#include "SocketDatagrama.h"

int puerto = 7200;
int tam = 1000;

int main(){
	SocketDatagrama sock(0);
	char *num = new char[tam];
	char ip[] = "192.168.43.123";
	for(int i = 0; i < 150; i++){
   		PaqueteDatagrama paks((char *)num, tam, ip, 7200);
   		for(int j = 0; j < tam; j++)
   			num[j] = i;
   		sock.envia(paks);
	}
}

