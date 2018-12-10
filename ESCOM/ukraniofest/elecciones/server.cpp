
#include "SocketDatagrama.h"
#include <sstream>
#include<iostream>
#include<set>

typedef struct
{
  unsigned long tel;
	char *rfc;
	char *partido;
} Voto;


#define max 10000
std::set<unsigned long> votes;

char *RFCgen()
{
	char *rfc=(char *)malloc(13*sizeof(char));
	for(int i=0;i<4;i++)
	{
		rfc[i]=65+(rand()%26);
	}
	for(int i=4;i<10;i++)
	{
		rfc[i]=48+(rand()%10);
	}
	for(int i=10;i<13;i++)
	{
		rfc[i]=65+(rand()%26);
	}
	return rfc;
}

unsigned long TELgen()
{
	char* tel = (char *)malloc(10*sizeof(char));
  tel[0] = '5';
  tel[1] = '5';

	for (int i = 2; i <= 10; i++) {
		tel[i] = 48+(rand()%10);
	}

	return strtoul(tel, NULL, 0);
}

char *PARgen()
{
	int i=rand()%10;
	switch (i)
	{
		case 0:return "PAN";
						break;
		case 1:return "PRI";
						break;
		case 2:return "PRD";
						break;
		case 3:return "VERDE";
						break;
		case 4:return "PT";
						break;
		case 5:return "MC";
						break;
		case 6:return "NA";
						break;
		case 7:return "MORENA";
						break;
		case 8:return "ES";
						break;
		case 9:return "BRONCO";
						break;
		default:break;
	}
}

int checkAndInsert(unsigned long num)
{
  if(votes.insert(num).second) {
    return 1;
	} else {
    return 0;
	}
}

using namespace std;

int main(int argc, char* argv[])
{
    int port = atoi(argv[1]);
    cout << "Port: " << port << endl;

    for(int i = 0; i < max; i++) {
      unsigned long tel = TELgen();
      if (checkAndInsert(tel)) {
        Voto votogen;
        votogen.partido = PARgen();
      	votogen.tel = tel;
      	votogen.rfc = RFCgen();
        cout << votogen.tel << " | " << votogen.rfc << " | " << votogen.partido << endl;
      }
  	}

    SocketDatagrama socket(port);
    Voto test;

    cout << "Votos generados: " << votes.size() << endl;

    PaqueteDatagrama paquete(sizeof(test));
    socket.recibe(paquete);

    PaqueteDatagrama paquete1((char *) &respuesta,sizeof(int), paquete.obtieneDireccion(),paquete.obtienePuerto());
    socket.envia(paquete1);

    /*
    while (1) {
        PaqueteDatagrama paquete(sizeof(unsigned int)*3);
        socket.recibe(paquete);
        num = (unsigned int *)paquete.obtieneDatos();

        cout << "\n\nLIMITE INFERIOR: " << num[0] << endl;
        cout << "LIMITE SUPERIOR: " << num[1] << endl;
        cout << "NUM: " << num[2] << endl;

        for (i = num[0]; i <= num[1] ; i++) {
            if (num[2]%i == 0) respuesta++;
        }

        PaqueteDatagrama paquete1((char *) &respuesta,sizeof(int),
            paquete.obtieneDireccion(),paquete.obtienePuerto());
        socket.envia(paquete1);

        respuesta = 0;
    }
    */

    return 0;
}
