#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

class SocketDatagrama{
	private:
		struct sockaddr_in direccionLocal;
		struct sockaddr_in direccionForanea;
		int s; //ID socket
	public:
		SocketDatagrama(int	);
		~SocketDatagrama();
		//Recibe un paquete tipo datagrama proveniente de este socket
		int	recibe(PaqueteDatagrama &p);
		//Envía un paquete tipo datagrama desde este socket
		int	envia(PaqueteDatagrama &p);
};
