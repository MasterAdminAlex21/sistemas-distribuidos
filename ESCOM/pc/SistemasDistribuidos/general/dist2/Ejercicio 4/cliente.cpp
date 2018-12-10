#include "SocketDatagrama.h"

int puerto = 7200;

int main(){
   SocketDatagrama sock(0);
   int num[2];
   num[0] = 100;
   num[1] = 98765;
   PaqueteDatragama enviar((char *)num, 8, "127.0.0.1", puerto);
   sock.envia(enviar);
}

