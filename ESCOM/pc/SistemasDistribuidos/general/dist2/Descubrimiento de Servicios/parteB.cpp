#include "SocketDatagrama.h"

int puerto = 7200;
int tam = 1000;
using namespace std;
int main(){
	int *num = new int[2];
	num[0] = 1;
	num[1] = 919;
	char ip[16];
	pid_t pid;

	SocketDatagrama sock1(0);

	SocketDatagrama sock2(7200);
	pid = fork();
	switch(pid){
		case -1:
			perror("Error en el fork");
			break;
		case 0:

			for(int i = 0; i < 154; i++){
				sprintf(ip, "192.168.0.%d", i + 100);
			   	PaqueteDatagrama paks((char *)num, 8, ip, puerto);
			   	sock1.envia(paks);
		   	}
		   	break;
		default:
			while(1) {
			  PaqueteDatagrama aux(8);
			  sock2.recibe(aux);
			  int *datos =(int *) aux.obtieneDatos();
			  std :: cout << datos[0] << " " << datos[1] << std :: endl; 
			  
			}
			break;
	}
}

