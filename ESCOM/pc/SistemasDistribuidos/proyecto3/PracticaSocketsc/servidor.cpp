
#include "SocketDatagrama.h"

using namespace std;

int main()
{
    SocketDatagrama socket(7200); 
    int *num; 
    while (1) { 
        PaqueteDatagrama paquete(sizeof(num)*2);
        socket.recibe(paquete);
        num = (int *)paquete.obtieneDatos(); 
        int respuesta = num[0] + num[1]; 
        cout << num[0] <<"+" << num[1] << "=" << respuesta << endl;
        PaqueteDatagrama paquete1((char *) &respuesta,sizeof(int),paquete.obtieneDireccion(),paquete.obtienePuerto());//Crea un datagrama para cada respuesta tal como se hace en c :D
        socket.envia(paquete1);
    }
    return 0;
}
