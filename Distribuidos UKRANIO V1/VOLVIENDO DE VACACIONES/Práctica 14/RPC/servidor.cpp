
#include "SocketDatagrama.h"
#include <stdio.h>

using namespace std;

int main()
{
    SocketDatagrama socket(7200); 

    //PaqueteDatagrama paquete(sizeof(unsigned int) * 3);
    PaqueteDatagrama paq((char *)mq1[0], 3 * sizeof(unsigned int), "127.0.0.1", 7200);
    socket.envia(paq);

    /*
    while (1) { 
        PaqueteDatagrama paquete(sizeof(num)*2);
        socket.recibe(paquete);
        num = (int *)paquete.obtieneDatos(); 
        int respuesta = num[0] + num[1]; 
        cout << num[0] <<"+" << num[1] << "=" << respuesta << endl;
        PaqueteDatagrama paquete1((char *) &respuesta,sizeof(int),paquete.obtieneDireccion(),paquete.obtienePuerto());//Crea un datagrama para cada respuesta tal como se hace en c :D
        socket.envia(paquete1);
    }
    */

    return 0;
}
