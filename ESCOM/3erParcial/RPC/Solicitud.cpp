
#include "Solicitud.h"
#include "SocketDatagrama.h"
#include "mensaje.h"

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

Solicitud::Solicitud()
{
	socketlocal = new SocketDatagrama(0);
}

void Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{
	struct mensaje ms;

	ms.messageType = 0;
	strcpy(ms.IP, IP);
	ms.puerto = puerto; 
	ms.operationId = operationId; 
	strcpy(ms.arguments, arguments);

	cout << "Using MESSAGE\n" << endl;
	cout << "IP: " << ms.IP << "\n" << endl;
    cout << "Port: " << ms.puerto << "\n" << endl;
    cout << "idOperation: " << ms.operationId << "\n" << endl;
    cout << "Arguments: " << ms.arguments << "\n" << endl;

	PaqueteDatagrama paq((char *)&ms, sizeof(struct mensaje), IP, puerto);
    socketlocal->envia(paq);

}
