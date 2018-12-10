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
#include <bits/stdc++.h>
#include "SocketDatagrama.h"
#include <bits/stdc++.h>
using namespace std;
int main(){
	SocketDatagrama SocketServidor(5000);
	SocketServidor.setTimeOut(2, 500000);
	PaqueteDatagrama X(300);
	SocketServidor.recibe(X);
	string PN = X.obtieneDatos();
	
	//cout <<"HH"<< X.obtieneDireccion()<< endl;
	//cout << X.obtieneDatos()<< endl;
	
	
	//SocketServidor.envia(Respuesta);
	//sendto(sock, send_data, strlen(send_data), 0 ,(struct sockaddr *)&server_addr, sizeof(struct sockaddr));
    

}
