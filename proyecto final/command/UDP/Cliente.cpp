#include "Solicitud.h"
#include "respuesta.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char** argv)
{
	if(argc!=7){
			printf("Algo anda mal ");
			exit(-1);
		}
		
	    Solicitud cliente;
	    respuesta *r;
		

		char * ip=argv[1];
		char *ip2=argv[2];
		char *ip3=argv[3];
		int port=atoi(argv[4]);

	    char cadena[400];
	    //char cadena2[400];

	    int n=atoi(argv[6]);
	   

		  ifstream fe(argv[5]);
   
      int i=0;

	  while (!fe.eof()) {
	    fe >> cadena;
        cout << "Servidor dice: "<<  cliente.doOperation(ip,port,i,10,cadena)<<"<br>"<<endl;

        i++;
	    cout << cadena << endl;
	  }
	  fe.close();//www.programacionenc.net/index.php?option=com_content&view=article&id=69:manejo-de-archivos-en-c&catid=37:programacion-cc&Itemid=55
    
   
	return 1;
} 