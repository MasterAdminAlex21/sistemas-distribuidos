#include <iostream>
#include "Solicitud.h"
#include "Mensaje.h"
#include "Palindromo.h"
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	//int nVeces = 0;
	if(argc!=3){
			printf("Algo anda mal ");
			exit(-1);
		}
		int n=atoi(argv[1]);
  ifstream fe;
  fe.open(argv[2]);
	Solicitud cl(7200);
	//int sumado = 1;
	char IP[16] = "192.168.43.108";
	char ip2[16]="192.168.43.17";
	char ip3[16]="192.168.43.90";
	string cad;
	int select = 0;
	bool a = true;
	while	(!fe.eof()) {
		a= true;
		cad = Palindromo::lectura(fe,n);
		//cout<<cad<<endl;
		//cout<<cad.c_str()<<endl;
		struct Mensaje *resp;
		while(a){
			switch(select) {
			case 0:
				resp = (struct Mensaje *)cl.doOperation(IP,6666,cad.length(),(char *)cad.c_str(), 0);
				if(resp !=NULL)
					a = false;
				select ++;
					break;
					case 1:
				resp = (struct Mensaje *)cl.doOperation(ip2,6666,cad.length(),(char *)cad.c_str(), 0);
				if(resp !=NULL)
					a = false;
				select ++;
					break;
					case 2:
				resp = (struct Mensaje *)cl.doOperation(ip3,6666,cad.length(),(char *)cad.c_str(), 0);
				if(resp !=NULL)
					a = false;
				select = 0;
					break;
		}
		}
		int resp2;
		memcpy(&resp2,(int*) resp->arguments,sizeof(int));
		cout<<resp2<<endl;
	}
	return 0;
}