#include <iostream>
#include <string.h>
#include <cmath>
#include "gfxModified.h"
#include <unistd.h>
#include <sys/time.h>

using namespace std;

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 600

int main()
{
    int i, contador;

    gfx_open(ANCHURA, ALTURA, "Ejemplo gfx_display_ascii");
    
    while(1) {
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

        gfx_color(87,1,2);
        
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

        /*
        for (i = 48; i < 58; i++){
            cout << "ASCII = " << i << endl;
            gfx_clear();
            gfx_display_ascii(10, 20, 30 , i);
            gfx_flush();
            sleep(1);
        }

        for (i = 65; i < 91; i++){            
            cout << "ASCII = " << i << endl;
            gfx_clear();
            gfx_display_ascii(30, 10 , 10, i);
            gfx_flush();            
            sleep(1);
        }
        */
    }
    

}


