
#include "SocketDatagrama.h"
#include <sstream>
#include "gfxModified.h"
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <cmath>

using namespace std;

#define ANCHURA 800
#define ALTURA 400

int main(int argc, char* argv[])
{
    if (argc != 2) {
        cout << "\n\tNot enough arguments\n\n" << endl;;
        return 1;
    }

    unsigned int *num;
    unsigned int *num2;

    int port = atoi(argv[1]);

    cout << "Port: " << port << endl;

    SocketDatagrama socket(port);

    gfx_open(ANCHURA, ALTURA, "Server Time");
    gfx_color(46, 68, 94);

    PaqueteDatagrama paquete(sizeof(unsigned int));
    socket.recibe(paquete);
    num = (unsigned int*)paquete.obtieneDatos();

    PaqueteDatagrama paquete2(sizeof(unsigned int));
    socket.recibe(paquete2);
    num2 = (unsigned int*)paquete2.obtieneDatos();

    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "%H:%M:%S", timeinfo);
    char currentTime[84] = "";
    sprintf(currentTime, "%s:%d", buffer, milli);
	
    PaqueteDatagrama paquete1((char *) &currentTime, sizeof(currentTime), paquete.obtieneDireccion(), paquete.obtienePuerto());
    socket.envia(paquete1);

    PaqueteDatagrama paquete11((char *) &currentTime, sizeof(currentTime), paquete2.obtieneDireccion(), paquete2.obtienePuerto());
    socket.envia(paquete11);

    int i=0;
    
    while (1) {

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        gettimeofday(&curTime, NULL);
        milli = curTime.tv_usec / 1000;
        strftime(buffer, 80, "%H:%M:%S", timeinfo);
        char currentTime[84] = "";
        sprintf(currentTime, "%s:%d", buffer, milli);

        if (i==0){
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
