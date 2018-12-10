#ifndef PAQUETEDATAGRAMA_H_
#define PAQUETEDATAGRAMA_H_
#include <string>
#include <cstring>
using namespace std;
class PaqueteDatagrama {
public:
	PaqueteDatagrama(char *, unsigned int, string , int );
	PaqueteDatagrama(unsigned int );
	~PaqueteDatagrama();
	string obtieneDireccion();
	unsigned int obtieneLongitud();
	int obtienePuerto();
	char *obtieneDatos();
	void inicializaPuerto(int);
	void inicializaIp( string );
	void inicializaDatos(char *);
private:
	char *datos; //Almacena los datos
	string ip; //Almacena la IP
	unsigned int longitud; //Almacena la longitude de la cadena de datos
	int puerto; //Almacena el puerto
}; 
#endif
