#include "Generador.h"
#define par pair< long long, int >
using namespace std;

Generador::Generador(int n, int edo){
	string estados[32];
	srand(getpid());
	llenaEstados( estados );
	int tam = -1;
	int puerto = 0;
	int pto = 7200;
	char ipPadre[] = "127.0.0.1";
	sms mensaje;
	PaqueteDatagrama *paquete = new PaqueteDatagrama( sizeof( sms ) );
	SocketDatagrama *socket = new SocketDatagrama( puerto );
	socket->setTimeout( 0, 250000 );
	par tmp;

	for( int i = 0; i < n; i++ ){
		time_t t = time(0);   // get time now
    	struct tm * now = localtime( & t );

    	stringstream aout;
		aout << now->tm_mday << "/" << (now->tm_mon+1) << "/" << (now->tm_year+1900);
    	string date = aout.str();

    	aout.str("");
    	aout << now->tm_hour << ":" << now->tm_min;
    	string hora = aout.str();

		mensaje.id = i;
		mensaje.origen = edo;
		mensaje.telOrig = creaTel( n );
		mensaje.telDest = creaTel( n );
		mensaje.cdOrig = estados[ rand()%32 ];
		mensaje.cdDest = estados[ rand()%32 ];
		mensaje.fecha = date;
		mensaje.hora = hora;

		string cad;
		for( int j = 0; j < 80; j++ ){
			cad += (char) (65 + rand()%58);
		}
		strcpy( mensaje.mensaje, cad.c_str() );

		while(1){
			paquete =  new PaqueteDatagrama( (char *) &mensaje , sizeof(sms), ipPadre , pto );
			int env = socket->envia( *paquete );
			
			paquete = new PaqueteDatagrama( sizeof(par) );
			int tam = socket->recibe( *paquete );
			memcpy( &tmp, paquete->obtieneDatos(), tam );
			
			if( tmp.first == i && tmp.second == edo ){
				//cout << "Confirmado: "<< edo << endl;
				break;
			}
			else{
				cout << "Falló enviando, estado " << edo << ", paquete "<< i << endl;
			}
		}
		cout << "Origen: " << mensaje.telOrig << " Destino: " << mensaje.telDest << endl;
	}
	delete socket;
}

Generador::~Generador(){
}

string Generador::creaTel( int n ){
	stringstream out;

	int a =  rand()%32 + 1;
	out << a;
	string estado = out.str();

	out.flush();
	a = rand()%(int)sqrt(n) + 1;
	stringstream aout;
	aout << a;
	string num = aout.str();

	if( estado.size() == 1 ) estado = "0"+estado;
	for( int i = 0; num.size() < 8; i++ ){
		num = "0" + num;
	}

	return estado+num;
}

void Generador::llenaEstados( string* estados ){
	estados[0] = "Aguascalientes";
	estados[1] = "Baja California";
	estados[2] = "Baja California Sur";
	estados[3] = "Campeche";
	estados[4] = "Chiapas";
	estados[5] = "Chihuahua";
	estados[6] = "Coahuila";
	estados[7] = "Colima";
	estados[8] = "Distrito Federal";
	estados[9] = "Durango";
	estados[10] = "Estado de México";
	estados[11] = "Guanajuato";
	estados[12] = "Guerrero";
	estados[13] = "Hidalgo";
	estados[14] = "Jalisco";
	estados[15] = "Michoacán";
	estados[16] = "Morelos";
	estados[17] = "Nayarit";
	estados[18] = "Nuevo León";
	estados[19] = "Oaxaca";
	estados[20] = "Puebla";
	estados[21] = "Querétaro";
	estados[22] = "Quintana Roo";
	estados[23] = "San Luis Potosí";
	estados[24] = "Sinaloa";
	estados[25] = "Sonora";
	estados[26] = "Tabasco";
	estados[27] = "Tamaulipas";
	estados[28] = "Tlaxcala";
	estados[29] = "Veracruz";
	estados[30] = "Yucatán";
	estados[31] = "Zacatecas";
}