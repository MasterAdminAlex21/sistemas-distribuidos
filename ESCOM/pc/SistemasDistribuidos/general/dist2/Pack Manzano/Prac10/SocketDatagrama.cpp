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
void SocketDatagrama::setTimeout(time_t segundos, suseconds_t microsegundos){
	timeout = true;	
	tiempoFuera.tv_sec = segundos;
	tiempoFuera.tv_usec = microsegundos;
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempoFuera, sizeof(tiempoFuera));	
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

void SocketDatagrama::setRTO(){
	srtt = 0;
	rttvar = 3*1000000;
	RTO = (srtt + 2*rttvar);
	RTT = 0;
	RTTmedida = 0;
	delta  = 0;
	setTimeout((int)(RTO/1000000.0), (int)((int)RTO%1000000));
	//cout << "RTO: " << (int)((int)RTO/1000000) << "segundos " << (int)((int)RTO%1000000) << "micros" << endl;
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
	setTimeout((int)(RTO/1000000.0), (int)((int)RTO%1000000));
}

int SocketDatagrama::recibeTimeoutRTO(PaqueteDatagrama & p){

	int retorno = recibe( p );

	gettimeofday(&tiempo2, NULL);	
	calculaRTO();
	if( retorno < 0 )
		cout << "Paquete perdido"<<endl;
	/*
	cout << "delta: " << delta << endl;
	cout << "srtt: " << srtt << endl;
	cout << "rttvar: " << rttvar << endl;
	cout << "RTTmedida: " << (int)((int)RTTmedida/1000000) << "s" << (int)((int)RTTmedida%1000000) << "ms" << endl;
	*/
	//cout << "RTO: " << (int)((int)RTO/1000000) << "segundos " << (int)((int)RTO%1000000) << "micros" << endl;
	return retorno;
}
