

#include "SocketDatagrama.h"
#include <sstream>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include "gfxModified.h"

using namespace std;

#define ANCHURA 800
#define ALTURA 400

int main(int argc, char* argv[])
{



	int ini,fin;		

    SocketDatagrama socket;

    char *serverip = argv[1];
    int serverport = atoi(argv[2]);

    cout << "Server: " << serverip << ":" << serverport << endl;

    unsigned int mq1[1];
    mq1[0] = 0;


    gfx_open(ANCHURA, ALTURA, "Client Time");
    gfx_color(46, 68, 94);
    


    struct tm * timeinfo;
    char buffer [80];
  timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;
ini=milli;
    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime(&rawtime);



    PaqueteDatagrama paq((char *)mq1, sizeof(unsigned int), serverip, serverport);
    socket.envia(paq);

    PaqueteDatagrama paquete2(84);
    socket.recibe(paquete2);


    gettimeofday(&curTime, NULL);
    milli = curTime.tv_usec / 1000;
fin=milli;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
	fin=(fin-ini)/2;
cout<<ini<<"--"<<fin<<endl;


    timeval tv ;
    int seg,min,ho,mili;
    
    
    char* respuesta=(char *)paquete2.obtieneDatos();
ho=(respuesta[0]-48)*10+(respuesta[1]-48);
min=(respuesta[3]-48)*10+(respuesta[4]-48);
seg=(respuesta[6]-48)*10+(respuesta[7]-48);
mili=(respuesta[9]-48)*10+(respuesta[10]-48);
mili=mili+(seg*1000)+(min*60000)+(ho*3600000);
tv.tv_sec=mili+fin;
//tv.tv_sec=mili;
settimeofday(&tv,NULL);

int i=0;
    while(1) {

           time(&rawtime);
        timeinfo = localtime(&rawtime);
    gettimeofday(&curTime, NULL);
    milli = curTime.tv_usec / 1000;
        strftime(buffer, 80, "%H:%M:%S", timeinfo);
        char currentTime[84] = "";
        sprintf(currentTime, "%s:%d", buffer, milli);
if(i==0){
	cout<<currentTime<<endl;
i++;
}
        gfx_clear();

        gfx_display_ascii(10,   20, 5 , currentTime[0]);
        gfx_display_ascii(50,   20, 5 , currentTime[1]);
 
        gfx_fill_rectangle(100, 35, 13, 13);
        gfx_fill_rectangle(100, 60, 13, 13);
 
        gfx_display_ascii(110,  20, 5 , currentTime[3]);
        gfx_display_ascii(150,  20, 5 , currentTime[4]);

        gfx_fill_rectangle(200, 35, 13, 13);
        gfx_fill_rectangle(200, 60, 13, 13);

        gfx_display_ascii(220,  20, 5 , currentTime[6]);
        gfx_display_ascii(270,  20, 5 , currentTime[7]);

        gfx_fill_rectangle(310, 35, 13, 13);
        gfx_fill_rectangle(310, 60, 13, 13);

        gfx_display_ascii(320,  20, 5 , currentTime[9]);
        gfx_display_ascii(370,  20, 5 , currentTime[10]);

        gfx_flush();
        usleep(10000);
    }

    return 0;
   
}
