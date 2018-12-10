#include "SocketDatagrama.h"
#include <bits/stdc++.h>
#include "archivo.h"
#include "LeerDirectorio.h"
#include "header.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define BUF_SIZE 1000

int main(int args, char *argv[]) {
	if (args != 4){
		cout << "Modo de uso: correr primeramente el cliente" << endl;
		cout << "./servidor IP PuertoServidor PuertoCliente" << endl;
		return 0;
	}
	string CARPETA = "libros_pruebas/";
	char *IP = argv[1];
	int PUERTO = atoi(argv[2]);
	int PUERTOCli = atoi(argv[3]);
	struct messageCS casteo;
	int  leidos = 0, destino;

	SocketDatagrama sock(PUERTO);
	cout << "Correr primeramente el cliente\nEsperando palabra...\n" << endl;
	struct messageSC sol;
	sol.count  = BUF_SIZE;
	sol.result = OK;
	sol.offset = 1;
	strcpy(sol.data, argv[3]);
	PaqueteDatagrama datos((char *)&sol, sizeof(struct messageSC), IP, PUERTOCli);
	sock.envia(datos);

	PaqueteDatagrama resp(sizeof(messageCS));
	//recibe msj con la palabra
	sock.recibe(resp);
	memcpy(&casteo, resp.obtieneDatos(), sizeof(messageSC));
	//string palabra = resp.obtieneDatos();
	string palabra = casteo.name;
	cout << palabra << endl;

	//abrimos directorio
	LeerDirectorio folder("./" + CARPETA);
	auto libros = folder.evaluar();
	sort(libros.begin(), libros.end());

	//realizamos la busqueda en c/u de los archivos 
	string abrir;
	int tam = palabra.length(), of[100];
	int array_size = 10000, offset;
	int posicion = 0;  
	char datEnvio[150];
	string envioString;

	for (const auto& nombre : libros){
		offset = 0;
		ifstream inFile;
		abrir = "./" + CARPETA + nombre;
		inFile.open(abrir);
		envioString = nombre + "\noffset: ";
		//cout << cstr <<endl;
		if(inFile){
			//cout << "\nBuscando en: " << nombre << endl;
			char * array = new char[array_size]; 
			posicion = 0; 

			while(!inFile.eof() && posicion < array_size){
				inFile.get(array[posicion]); 
				posicion++;
			}
			array[posicion-1] = '\0'; 

			for(int i = 0; array[i] != '\0'; i++){
				for(int j = 0; palabra[j] != '\0' && j < tam ; j++){
			        if(array[i] != palabra[j])
			        	break;
			        else{
			         	i++;
			          	if(palabra[j+1] == '\0'){
			          		offset = i-tam;
			          		if(i!=0)
			          			envioString = envioString + ", ";
			          		envioString = envioString + to_string(offset);
			          		//strcat(cadena1,cadena2);
				            //cout << "Word Found in File at position " << (i-tam) << endl;
			          	}
			        }
	      		}
			}
			envioString = envioString + ";\n";
			//cout << envioString << endl;
			const char * c = envioString.c_str();
			//enviamos informacion del libro 
			struct messageSC solicitud;
			solicitud.count  = BUF_SIZE;
			solicitud.result = OK;
			solicitud.offset = 1;
			strcpy(solicitud.data, c);

			PaqueteDatagrama datos((char *)&solicitud, sizeof(struct messageSC), IP, PUERTOCli);
			sock.envia(datos);
			//cout << "se envio datos de 1 libro.." << endl;
			
		}
		else
			cout << "\nNo se pudo abrir: " << nombre << endl;
	}	
	cout << "Listo! " << endl;
	while(1){}
	close(destino);
	return 0;
}