
#include "SocketDatagrama.h"
using namespace std;

int main()
{
    int num[2]; 
    char ip[] = "10.100.69.234";
    int *respuesta; 
    SocketDatagrama socket;
    num[0] = 2;
    num[1] = 5;
    PaqueteDatagrama paq((char *)num,2 * sizeof(int),ip,7200);
    socket.envia(paq); 
    PaqueteDatagrama paquete1(sizeof(int)); 
    socket.recibe(paquete1); 
    respuesta = (int *)paquete1.obtieneDatos(); 
    std::cout << "La resultado es: " << *respuesta << std::endl;

    return 0;
}
