#include "SocketDatagrama.h"
#include "header.h"
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	SocketDatagrama sock(0);
	mensajeCS mensaje;
	mensajeSC res;
	int destino;
	mensaje.opcode = READ;
	mensaje.offset = 0; 	 
	char ip[16];
	strcpy(mensaje.name,argv[3]);
	strcpy(ip,argv[1]);
	int port = atoi(argv[2]);
	if((destino = open(argv[3], O_WRONLY|O_TRUNC|O_CREAT,0666)) == -1){
       perror(argv[3]);
       exit(-1);
    }

	while(1){
		PaqueteDatagrama pak((char *)&mensaje,sizeof(mensaje),ip,port);
		
		sock.envia(pak);
		PaqueteDatagrama pak1(sizeof(mensajeSC));
		sock.setTimeout(1, 0);
		int result = sock.recibeTimeout(pak1);
		std :: cout << result << std :: endl;
		if(result < 0)
			continue;
		memcpy(&res,pak1.obtieneDatos(),sizeof(mensajeSC));
		std :: cout << res.result << std :: endl;
		if(res.result != OK)
			continue;
		if(res.count == 0)
			break;
		std :: cout << res.count << std :: endl;
		//	getchar();
		mensaje.offset += res.count;
		write(destino,res.data,res.count); 
	}
	   
   	close(destino);
   	return 0;
}

