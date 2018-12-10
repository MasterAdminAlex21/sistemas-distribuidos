
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"

#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    struct mensaje serverms;
    const char* pt = argv[1];
    stringstream strPort;
    unsigned int *num, i = 0, respuesta = 0;
    int port;

    strPort << pt;
    strPort >> port;

    cout << "Port: " << port << endl;

    SocketDatagrama socket(port);

    while (1) {
        PaqueteDatagrama paquete(sizeof(struct mensaje));
        cout << "Recibi: " << socket.recibe(paquete) << endl;
        memcpy( &serverms, paquete.obtieneDatos(), sizeof(struct mensaje));
        cout << "From SERVER" << endl;
        cout << "IP: " << serverms.IP << "\n" << endl;
        cout << "Port: " << serverms.puerto << "\n" << endl;
        cout << "idOperation: " << serverms.operationId << "\n" << endl;
        cout << "Arguments: " << serverms.arguments << "\n" << endl;
    }
    
    return 0;
}
