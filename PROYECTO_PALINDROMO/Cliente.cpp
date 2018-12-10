#include "Solicitud.h"
#include "respuesta.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char** argv)
{
	if(argc<3)
		exit(-1);
	
    Solicitud cliente;
    respuesta *r;

	char * ip=argv[1];
	int port=atoi(argv[2]);

    char cadena[400];
    //char cadena2[400];

   

	  ifstream fe("/home/arhelicortes/Escritorio/PROYECTO_PALINDROMO/Fichero.txt");

      int i=0;

	  while (!fe.eof()) {
	    fe >> cadena;
        cout << "Servidor dice: "<<  cliente.doOperation(ip,port,i,10,cadena)<<endl;

        i++;
	    cout << cadena << endl;
	  }
	  fe.close();//www.programacionenc.net/index.php?option=com_content&view=article&id=69:manejo-de-archivos-en-c&catid=37:programacion-cc&Itemid=55
    
   
	return 1;
} 