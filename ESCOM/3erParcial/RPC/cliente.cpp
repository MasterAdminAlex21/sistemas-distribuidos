
#include "SocketDatagrama.h"
using namespace std;

int main()
{
    unsigned int num[3]; 
    char ip[] = "127.0.0.1";
    int *respuesta;

    SocketDatagrama socket(7200);
    PaqueteDatagrama paquete1(sizeof(unsigned int) * 3); 
    socket.recibe(paquete1); 
    respuesta = (int *)paquete1.obtieneDatos(); 
    std::cout << *respuesta << std::endl;

    /*
    PaqueteDatagrama paq((char *)num,2 * sizeof(int),ip,7200);
    socket.envia(paq); 
    respuesta = (int *)paquete1.obtieneDatos(); 
    std::cout << "La resultado es: " << *respuesta << std::endl;
    */

    return 0;
}
