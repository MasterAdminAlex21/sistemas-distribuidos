
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"

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
#include <iostream>
#include <vector>
#include <string.h>
#include <thread>
#include <sstream>
#include<iostream>
#include <string>
#include<set>

using namespace std;

typedef struct
{
	char *tel;
	char *rfc;
	char *partido;
} Voto;

Voto Votogen();
char *RFCgen();
char *TELgen();
char *PARgen();
void FSend1(char* Svoto);
void FSend2(char* Svoto);
void FSend3(char* Svoto);
//void FSend(SocketDatagramas,char ip[15],int puerto);

int checkAndInsert(unsigned long);

#define max 1000
std::set<unsigned long> votes;
SocketDatagrama s(6666);
char *ip;

int main(int argc, char* argv[])
{
	ip = argv[1];

	/*char ips[3][15];
	int puertos[3];
	char *aux;
	unsigned int num = 4294967291;
	for(int i=0; i<3; i++){
		cout << "Ingresa la ip del SERVIDOR " << i << ": ";
		cin >> ips[i];
		cout << "Ingresa puerto del SERVIDOR " << i << ": ";
		cin >> puertos[i];
	}*/
	/*
	char ip[15];
	int puerto;
	cout << "Ingresa la ip del SERVIDOR " << ": ";
	cin >> ip;
	cout << "Ingresa puerto del SERVIDOR " << ": ";
	cin >> puerto;
	//FSend(s,ip,puerto);
	*/
	FILE* votantes = fopen( "/home/jesus/Desktop/ESCOM/ukraniofest/pf/ClienteUDP/votantes.txt", "a+");

	   if(votantes == NULL)
	   {
	      printf("Error!");
	      exit(1);
	   }

	for(int i = 0; i < max; i++) {
		while (1) {
			printf("\n ----------------- \n");
			char* tel = TELgen();
			printf("TELG:%s\n",tel);
			if (checkAndInsert(strtoul(tel, NULL, 0)) == 1) {
				Voto votogen;
				votogen.partido = PARgen();
				votogen.tel = tel;
				votogen.rfc = RFCgen();
				cout << votogen.tel << " | " << votogen.rfc << " | " << votogen.partido << endl;

				char *Svoto=(char *)malloc(100*sizeof(char));
				strcat(Svoto, votogen.tel);
				strcat(Svoto,",");
				strcat(Svoto, votogen.rfc);
				strcat(Svoto,",");
				strcat(Svoto, votogen.partido);
				fprintf(votantes, "%s\n", Svoto);

				thread H1(FSend1, Svoto);
				thread H2(FSend2, Svoto);
				thread H3(FSend3, Svoto);

				H1.join();
				H2.join();
				H3.join();

				//PaqueteDatagrama p((char *) Svoto ,100*sizeof(char), ip, puerto);
				//PaqueteDatagrama p( &val ,sizeof(Voto), ip, puerto);
				//s.envia(p);
				break;
			}
		}
	}

	/*
	Voto val;
	val=Votogen();
	char *aux;
	aux=val.tel;
	char *Svoto=(char *)malloc(100*sizeof(char));
	Svoto=aux;
	strcat(Svoto,",");
	aux=val.rfc;
	strcat(Svoto,aux);
	Svoto=strcat(Svoto,",");
	aux=val.partido;
	Svoto=strcat(Svoto,aux);
//	strcat(Svoto,'\0');
	printf("trama:%s\n",Svoto);
	/*unsigned int val[3];
	val[0] = 2;
	int ntotal = num/3;
	val[2] = num;
	for(int i=0; i<3; i++){
		if(i==2){
			val[1] = num-1;
		}else{
			val[1] = val[0]+ ntotal;
		}
		*/
		//PaqueteDatagrama p((char *) Svoto ,100*sizeof(char), ip, puerto);
		//PaqueteDatagrama p( &val ,sizeof(Voto), ip, puerto);
		//s.envia(p);
		/*val[0] = val[1]+1;
	}
	int res;
	for(int i=0; i<3; i++){
		PaqueteDatagrama p(sizeof(int));
		s.recibe(p);
		res = (int) *p.obtieneDatos();
		if(res){
			cout << "¡NO es primo!\n";
		}
	}
	cout << "¡Es primo!\n";*/
	fclose(votantes);
}

/*void FSend(SocketDatagrama s, char ip[15], int puerto)
{
	for(int i = 0; i < max; i++) {
		while (1) {
			char* tel = TELgen();
			printf("TELG:%s\n",tel);
			if (checkAndInsert(strtoul(tel, NULL, 0)) == 1) {
				Voto votogen;
				votogen.partido = PARgen();
				votogen.tel = tel;
				votogen.rfc = RFCgen();
				cout << votogen.tel << " | " << votogen.rfc << " | " << votogen.partido << endl;

				char *Svoto=(char *)malloc(100*sizeof(char));
				strcat(Svoto, tel);
				strcat(Svoto,",");
				strcat(Svoto, votogen.rfc);
				strcat(Svoto,",");
				strcat(Svoto, votogen.partido);
				printf("trama:%s\n",Svoto);

				PaqueteDatagrama p((char *) Svoto ,100*sizeof(char), ip, puerto);
				//PaqueteDatagrama p( &val ,sizeof(Voto), ip, puerto);
				s.envia(p);
				break;
			}
		}
	}
}*/
void FSend1(char* Svoto)
{
	//cout << "1:" << Svoto << endl;
	PaqueteDatagrama p((char *) Svoto , 100*sizeof(char), ip, 8080);
	s.envia(p);
	usleep(100000);
}

void FSend2(char* Svoto)
{
	//cout << "2:" << Svoto << endl;
	PaqueteDatagrama p((char *) Svoto , 100*sizeof(char), ip, 8081);
	s.envia(p);
	usleep(100000);
}

void FSend3(char* Svoto)
{
	//cout << "3:" << Svoto << endl;
	PaqueteDatagrama p((char *) Svoto , 100*sizeof(char), ip, 8082);
	s.envia(p);
	usleep(100000);
}

Voto Votogen()
{
	Voto votogen;
	char *rfc;
	char *tel;
	char *par;
	rfc=RFCgen();
	tel=TELgen();
	par=PARgen();
	votogen.partido=par;
	//printf("entra: %s\n",votogen.partido);
	votogen.tel=tel;
	//printf("entra: %s\n",votogen.tel);
	votogen.rfc=rfc;
	//printf("entra: %s\n",votogen.rfc);
	return votogen;
}

char *RFCgen()
{
	//srand(time(NULL));
	char *rfc=(char *)malloc(14*sizeof(char));
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
	rfc[13] = '\0';
	return rfc;
}

char *TELgen()
{
	char *tel=(char *)malloc(11*sizeof(char));
	for(int i=0;i<10;i++)
	{
		tel[i]=48+(rand()%9);
	}
	tel[10] = '\0';

	return tel;
}

char *PARgen()
{
	//srand(time(NULL));
	//char *par=(char *)malloc(sizeof(char));
	int i=rand()%10;
	switch (i)
	{
		case 0:return (char*)"PAN";
						break;
		case 1:return (char*)"PRI";
						break;
		case 2:return (char*)"PRD";
						break;
		case 3:return (char*)"VERDE";
						break;
		case 4:return (char*)"PT";
						break;
		case 5:return (char*)"MC";
						break;
		case 6:return (char*)"NA";
						break;
		case 7:return (char*)"MORENA";
						break;
		case 8:return (char*)"ES";
						break;
		case 9:return (char*)"BRONCO";
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
