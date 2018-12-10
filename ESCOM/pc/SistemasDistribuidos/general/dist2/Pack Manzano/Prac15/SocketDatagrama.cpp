#include "SocketDatagrama.h"

using namespace std;

SocketDatagrama::SocketDatagrama(int puertoL)
{
   s = socket(AF_INET, SOCK_DGRAM, 0);

   bzero((char *)&direccionLocal, sizeof(struct sockaddr_in));
   bzero((char *)&direccionForanea, sizeof(struct sockaddr_in));      

   direccionLocal.sin_family = AF_INET;
   direccionLocal.sin_addr.s_addr = INADDR_ANY;
   direccionLocal.sin_port = htons(puertoL);
   int b = bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));

}

SocketDatagrama::~SocketDatagrama()
{
   close(s);
}

//Recibe un paquete tipo datagrama proveniente de este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p)
{
   int retorno;
   socklen_t clilen; //Ojo no compila si es un tipo int en C
   clilen = sizeof(direccionForanea);
   retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
   p.inicializaPuerto(ntohs(direccionForanea.sin_port));
   p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
   gettimeofday(&tiempoRecibido, NULL);
   
   return retorno;
}

//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p)
{
   direccionForanea.sin_family = AF_INET;
   direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
   direccionForanea.sin_port = htons(p.obtienePuerto());
   return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
}

void activaAlarma( int sig ){
	cout << "Se activó la alarma"<<endl;
}

void SocketDatagrama::setTimeout(){
	timeout = true;	
	alarma.sa_handler = activaAlarma;
	alarma.sa_flags = 0;
	sigaction( SIGALRM, &alarma, NULL );
}

void SocketDatagrama::setAlarma( time_t segundos, suseconds_t microsegundos ){
	tiempoFuera.tv_usec = microsegundos;
	tiempoFuera.tv_sec = segundos;
	cout << "Timeout: " << segundos << " " << microsegundos<<endl;
	sigaction( SIGALRM, &alarma, NULL );
	if( segundos < 0 )
		ualarm( microsegundos, 0 );
	else
		alarm( segundos );
}

struct timeval SocketDatagrama::getTiempoRecibe(){
	return tiempoRecibido;
}

struct timeval SocketDatagrama::getTimeout(){
	return tiempoFuera;
}

void SocketDatagrama::unsetTimeout(){
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, NULL, 0);
	timeout = false;
}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p)
{
   int retorno;
   struct timeval tiempo1;
   struct timeval tiempo2;
   struct timeval res;
		
   socklen_t clilen; //Ojo no compila si es un tipo int en C
   clilen = sizeof(direccionForanea);
   gettimeofday(&tiempo1, NULL);
   retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
   if(retorno < 0){
		if (errno == EWOULDBLOCK)
		{
			fprintf(stderr, "Tiempo para recepción transcurrido\n");	
		}	
		else
			fprintf(stderr, "Error en recvfrom\n");
   }
   else{
		gettimeofday(&tiempo2, NULL);
		timersub(&tiempo2,&tiempo1,&res);
		//cout << res.tv_sec << " " << res.tv_usec << endl;		
	}	
   p.inicializaPuerto(ntohs(direccionForanea.sin_port));
   p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
   
   return retorno;
}

int SocketDatagrama :: setBroadcast(){
	int yes = 1;
	int broad = setsockopt( s, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int) );
	if( broad < 0 ){
		std :: cout << "Error en el Broadcast" << std :: endl;
		exit(0);
	}
	return 1;
}

void SocketDatagrama :: unsetBroadcast(){
	int yes = 0;
	int broad = setsockopt( s, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int) );
	if( broad < 0 ){
		std :: cout << "Error en el Broadcast" << std :: endl;
		exit(0);
	}
	return 1;
}


void SocketDatagrama::setRTO(){
	srtt = 0;
	rttvar = 3000000;
	RTO = (srtt + 2*rttvar);
	RTT = 0;
	RTTmedida = 0;
	delta  = 0;
	tiempoFuera.tv_sec = (int)(RTO/1000000.0);
	tiempoFuera.tv_usec = (int)((int)RTO%1000000);
}

int SocketDatagrama::enviaTimeoutRTO(PaqueteDatagrama & p){
	gettimeofday(&tiempo1, NULL);
	return envia( p );
}

void SocketDatagrama::calculaRTO(){
	timersub(&tiempo2, &tiempo1, &tiempo3);	
	RTTmedida = fabs( (tiempo3.tv_sec*1000000) + tiempo3.tv_usec);
	delta = fabs(RTTmedida-srtt);
	srtt = fabs(srtt-0.125*delta);
	rttvar = fabs(rttvar+.25*(fabs(delta)-rttvar));
	RTO = fabs(srtt+4*rttvar);
}

int SocketDatagrama::recibeTimeoutRTO(PaqueteDatagrama & p){
	
	int retorno;
	
	socklen_t clilen; //Ojo no compila si es un tipo int en C
	clilen = sizeof(direccionForanea);

	tiempoFuera.tv_usec = (int)((int)RTO%1000000);
	tiempoFuera.tv_sec = (int)(RTO/1000000.0);
	
	//cout << "Timeout: " << tiempoFuera.tv_sec << " " << tiempoFuera.tv_usec << endl;
	if( tiempoFuera.tv_sec < 1 ){
		ualarm( max(tiempoFuera.tv_usec, (suseconds_t)500000), 0 );
	}
	else
		alarm( tiempoFuera.tv_sec );

	retorno = recvfrom(s, (char *) p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &clilen);
	alarm(0);
	ualarm( 0, 0 );
	if( retorno > 0 ){
		p.inicializaPuerto(ntohs(direccionForanea.sin_port));
		p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	}
	
	gettimeofday(&tiempo2, NULL);
	tiempoRecibido = tiempo2;	
	calculaRTO( );

	if( retorno < 0 )
		cout << "Paquete perdido\n";

	return retorno;
}
