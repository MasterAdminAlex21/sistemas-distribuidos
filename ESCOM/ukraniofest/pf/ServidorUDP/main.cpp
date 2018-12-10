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
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
	char *tel;
	char *rfc;
	char *partido;
}Voto;

int esPrimo(unsigned int ini, unsigned fin, unsigned num){
	for(int i=ini; i<=fin; i++){
		if(num%i==0){
			return 1;
		}
	}
	return 0;
}

int main(){

	vector<Voto> votes;
	unsigned long index = 0;
	int puerto;

	cout << "Ingresa el puerto: \n";
	cin >> puerto;

	SocketDatagrama s(puerto);
	char* rfc=(char *)malloc(100*sizeof(char));
	//unsigned int val[3], res;
	cout << "inicia servicio...\n";

	unsigned long numVotes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	while(index < 300) {
		Voto val;
		PaqueteDatagrama p(40*sizeof(char));
		//PaqueteDatagrama p(sizeof(Voto));
		//printf("entra:\n");
  	s.recibe(p);
		//printf("entra:\n");
		rfc = p.obtieneDatos();

		memcpy(val, p.obtieneDatos(), sizeof(val));

		char *pch;
		pch = strtok (rfc,",");
		int i = 0;
	  while (pch != NULL)
	  {
			if(i==0)
			{
	    	//printf ("%s\n",pch);
				val.tel=pch;
	    	//pch = strtok (NULL, ",");
			}
			else if(i==1)
			{
				//printf ("%s\n",pch);
				val.rfc=pch;
			}
			else
			{
				//printf ("%s\n",pch);
				val.partido=pch;
			}
			pch = strtok (NULL, ",");
			i++;
	  }
		//memcpy(&val,p.obtieneDatos(),sizeof(Voto));
		//printf("entra: %s\n",p.obtieneDatos());
		//val=p.obtieneDatos();
		printf("entraP:\n");
		//printf("entra: %s\n",rfc);
		//printf("entra: %s\n",val.tel);
		//printf("entra: %s\n",val.rfc);
		//printf("entra: %s\n",val.partido);

		votes.push_back(val);

		cout << "votes[" << index << "].tel = " << (char*)(votes[index].tel) << endl;
		cout << "votes[" << index << "].rfc = " << (char*)(votes[index].rfc) << endl;
		cout << "votes[" << index << "].partido = " << (char*)(votes[index].partido) << endl;

		if (strcmp((char*)votes[index].partido, "PAN")==0){
			numVotes[0]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "PRI")==0) {
			numVotes[1]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "PRD")==0) {
			numVotes[2]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "VERDE")==0) {
			numVotes[3]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "PT")==0) {
			numVotes[4]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "MC")==0) {
			numVotes[5]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "NA")==0) {
			numVotes[6]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "MORENA")==0) {
			numVotes[7]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "ES")==0) {
			numVotes[8]++;
			index++;
			continue;
		} else if (strcmp((char*)votes[index].partido, "BRONCO")==0) {
			numVotes[9]++;
			index++;
			continue;
		}

					/*
		switch ((char*)votes[index].partido) {
			case "PAN": numVotes[0]++; break;
			case "PRI": numVotes[1]++; break;
			case "PRD": numVotes[2]++; break;
			case "VERDE": numVotes[3]++; break;
			case "PT": numVotes[4]++; break;
			case "MC": numVotes[5]++; break;
			case "NA": numVotes[6]++; break;
			case "MORENA": numVotes[7]++; break;
			case "ES": numVotes[8]++; break;
			case "BRONCO": numVotes[9]++; break;
		}*/

	}

	cout << "Votos PAN:		" << numVotes[0] << endl;
	cout << "Votos PRI:		" << numVotes[1] << endl;
	cout << "Votos PRD:		" << numVotes[2] << endl;
	cout << "Votos VERDE:	" << numVotes[3] << endl;
	cout << "Votos PT:		" << numVotes[4] << endl;
	cout << "Votos MC:		" << numVotes[5] << endl;
	cout << "Votos NA:		" << numVotes[6] << endl;
	cout << "Votos MORENA:" << numVotes[7] << endl;
	cout << "Votos ES:		" << numVotes[8] << endl;
	cout << "Votos BRONCO:" << numVotes[9] << endl;

	//printf("%d\n",votes.size());
	/*for(int j=0;j<votes.size();j++)
	{
		printf("entra: %s\n", votes[j].tel);
		printf("entra: %s\n", votes[j].rfc);
		printf("entra: %s\n", votes[j].partido);
		printf("\n");
	}*/
	/*
	Voto res;
	for(int j=0;j<it;j++)
	{
		res=Votes[j];
		printf("entra: %s\n",res.tel);
		printf("entra: %s\n",res.rfc);
		printf("entra: %s\n",res.partido);
		//std::cout <<<< *it;
	}
	*/

		//memcpy(val, p.obtieneDatos(), 3*sizeof(int));
/*	for(int i =0 ; i<3; i++){
			cout << val[i] << " ";
		}
		cout << "\n\n";
  	char ip[] = "127.0.0.1";
  	res = esPrimo(val[0], val[1], val[2]);
  	PaqueteDatagrama p2((char*) &res, sizeof(int), ip, 7200);
  	s.envia(p2);
	cout<<"Calculo finalizado\n"<<endl;

}*/
}
