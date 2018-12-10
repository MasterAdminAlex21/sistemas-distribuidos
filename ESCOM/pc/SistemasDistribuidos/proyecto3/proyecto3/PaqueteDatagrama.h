class PaqueteDatagrama {
	public:
 		PaqueteDatagrama(char *C, unsigned int len, char *ip, int port);
		PaqueteDatagrama(unsigned int len);
 		//~PaqueteDatagrama();
	 	char *obtieneDireccion();
 		unsigned int obtieneLongitud();
 		int obtienePuerto();
 		char *obtieneDatos();
 		void inicializaPuerto(int P);
 		void inicializaIp(char *X);
 		void inicializaDatos(char *X);
	private:
 		char *datos; //Almacena los datos
 		char ip[16]; //Almacena la IP
 		unsigned int longitud; //Almacena la longitud de la cadena de datos
 		int puerto; //Almacena el puerto
}; 