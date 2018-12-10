
#include "SocketDatagrama.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    const char* pt = argv[1];
    stringstream strPort;
    unsigned int *num, i = 0, respuesta = 0;
    int port;

    strPort << pt;
    strPort >> port;

    cout << "Port: " << port << endl;

    SocketDatagrama socket(port);

    while (1) {
        PaqueteDatagrama paquete(sizeof(unsigned int)*3);
        socket.recibe(paquete);
        num = (unsigned int *)paquete.obtieneDatos();

        cout << "\n\nLIMITE INFERIOR: " << num[0] << endl;
        cout << "LIMITE SUPERIOR: " << num[1] << endl;
        cout << "NUM: " << num[2] << endl;

        for (i = num[0]; i <= num[1] ; i++) {
            if (num[2]%i == 0) respuesta++;
        }

        PaqueteDatagrama paquete1((char *) &respuesta,sizeof(int), 
            paquete.obtieneDireccion(),paquete.obtienePuerto());
        socket.envia(paquete1);

        respuesta = 0;
    }
    
    return 0;
}
