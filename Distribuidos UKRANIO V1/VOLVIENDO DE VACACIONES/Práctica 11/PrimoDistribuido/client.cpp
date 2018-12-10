
#include "SocketDatagrama.h"
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{

    if (argc != 6) {
        cout << "\n\tNot enough arguments\n\n" << endl;;
        return 1;
    }

    char *ip1 = argv[1], *ip2 = argv[3];
    int port1 = 0, port2 = 0;
    int *respuesta1;
    int *respuesta2;
    SocketDatagrama socket;
    unsigned int mq1[3];
    unsigned int mq2[3];
    unsigned int bigNum = 0;

    const char* pt1 = argv[2];
    const char* pt2 = argv[4];
    const char* number = argv[5];

    stringstream strPort1;
    stringstream strPort2;
    stringstream strBigNum;

    strPort1 << pt1;
    strPort1 >> port1;
    
    strPort2 << pt2;
    strPort2 >> port2;

    strBigNum << number;
    strBigNum >> bigNum;

    cout << "NUM: " << bigNum << endl;

    cout << "\nServidor 1-> " << ip1 << ":" << port1 << endl;

    /*Maquina 1 es la que tenga más poder de procesamiento*/
    /*Se asigna 0.75 de la carga total por los calculos previamente hechos*/
    mq1[0] = 1;
    mq1[1] = (unsigned int)bigNum*0.65;
    mq1[2] = bigNum;

    cout << "LIM INFERIOR 1: " << mq1[0] << endl;
    cout << "LIM SUPERIOR 1: " << mq1[1] << endl;

    /*Maquina 2*/
    cout << "\nServidor 2 -> " << ip2 << ":" << port2 << endl;
    mq2[0] = mq1[1] + 1;
    mq2[1] = bigNum;
    mq2[2] = bigNum;

    cout << "LIM INFERIOR 2: " << mq2[0] << endl;
    cout << "LIM SUPERIOR 2: " << mq2[1] << endl;

    PaqueteDatagrama paq((char *)mq1, 3 * sizeof(unsigned int), ip1, port1);
    socket.envia(paq);
    
    PaqueteDatagrama paq2((char *)mq2, 3 * sizeof(unsigned int), ip2, port2);
    socket.envia(paq2);
    
    PaqueteDatagrama paquete1(sizeof(int));
    socket.recibe(paquete1);
    respuesta1 = (int *)paquete1.obtieneDatos();

    PaqueteDatagrama paquete2(sizeof(int));
    socket.recibe(paquete2);
    respuesta2 = (int *)paquete2.obtieneDatos();

    int a = *respuesta1 + *respuesta2;
    if(a > 2) 
        std::cout << "\n\nNúmero NO primo" << std::endl;
    else
        std::cout << "\n\nNúmero PRIMO!" << std::endl;
    
    return 0;
   

   
}
