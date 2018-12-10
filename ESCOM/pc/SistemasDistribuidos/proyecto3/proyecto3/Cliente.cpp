#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "SocketDatagrama.h"
#include <bits/stdc++.h>
using namespace std;
int main(){
	SocketDatagrama SocketCliente(3000);
	PaqueteDatagrama paqueteEnviar((char*)"ENVIO", 6, (char*)"192.168.0.110", 5000);
	SocketCliente.envia(paqueteEnviar);

	/*PaqueteDatagrama X(30);
	SocketCliente.recibe(X);
	cout << X.obtieneDatos() << endl;*/
	//sendto(sock, send_data, strlen(send_data), 0 ,(struct sockaddr *)&server_addr, sizeof(struct sockaddr));
    

}
