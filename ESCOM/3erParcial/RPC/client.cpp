
#include "Solicitud.h"
#include <sstream>
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{

    if (argc != 5) {
        cout << "\n\tNot enough arguments\n\n" << endl;;
        return 1;
    }

    char *ip = argv[1], *arguments = argv[4];
    int port = 0;
    int idOperation = 0;

    const char* pt = argv[2];    
    const char* idOp = argv[3];

    stringstream strPort;
    stringstream strIdOp;

    strPort << pt;
    strPort >> port;

    strIdOp << idOp;
    strIdOp >> idOperation;

    Solicitud cliente;
    cliente.doOperation(ip, port, idOperation, arguments);

    /*
    PaqueteDatagrama paq((char *)mq1, 3 * sizeof(unsigned int), ip1, port1);
    socket.envia(paq);
    
    PaqueteDatagrama paquete2(sizeof(int));
    socket.recibe(paquete2);
    respuesta2 = (int *)paquete2.obtieneDatos();

    int a = *respuesta1 + *respuesta2;
    if(a > 2) 
        std::cout << "\n\nNúmero NO primo" << std::endl;
    else
        std::cout << "\n\nNúmero PRIMO!" << std::endl;
    */

    return 0;
   

   
}
