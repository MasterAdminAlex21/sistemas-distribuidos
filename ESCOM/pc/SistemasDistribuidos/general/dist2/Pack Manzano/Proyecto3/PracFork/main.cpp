#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int puerto = 7200;

int main(){
	pid_t pid;

	string ip = "192.168.0.";
	for( int i = 1; i < 254; i++ ){
		pid = fork();
		if( pid != 0 ){
			PaqueteDatagrama *paquete = new PaqueteDatagrama( sizeof(int) );
			SocketDatagrama *socket = new SocketDatagrama( puerto );
		}
	}

	return 0;
}