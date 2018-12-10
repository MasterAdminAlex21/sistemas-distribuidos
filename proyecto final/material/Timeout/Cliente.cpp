#include <iostream>
#include <cstring>
#include "Solicitud.h"
#include "Mensaje.h"

using namespace std;

int main(int argc, char *argv[]) {
	int nVeces = 0;
	if(argc == 2)
		nVeces = atoi(argv[1]);
	else {
		cout << "Ingrese el comando de forma correcta" << endl;
		cout << "\t ./Cliente [numero de ciclos]";
		exit(-2);
	}
	Solicitud cl(7200);
	unsigned int nbdLocal = 0;
	unsigned int nbdServidor = 0;
	int sumado = 1;
	char IP[16] = "10.100.66.80";
	
	struct Mensaje *resp = (struct Mensaje *)cl.doOperation(IP,6666,1,(char *)&sumado, 0);
	memcpy(&nbdLocal,(unsigned int *)resp->arguments, sizeof(unsigned int));
	memcpy(&nbdServidor,(unsigned int *)resp->arguments, sizeof(unsigned int));
	cout << "nbd recibido: " << nbdLocal << endl;

	cout << "\nHaciendo " << nVeces << " depositos de " << sumado << endl;
	for(int i = 0 ; i < nVeces ; i++) {
		cout << "\ndeposito " << i + 1 << endl;
		nbdLocal += sumado;
		struct Mensaje *resp = (struct Mensaje *)cl.doOperation(IP,6666,2,(char *)&sumado, i + 1);
		memcpy(&nbdServidor,(unsigned int *)resp->arguments, sizeof(unsigned int));
		cout << "nbd recibido: " << nbdServidor << endl;
		if(nbdLocal != nbdServidor) {
			cout << "Inconcistencia de BD" << endl;
			exit(-3);
		}
	}
	return 0;
}