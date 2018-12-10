
#include <iostream>
#include <string.h>
#include <cmath>
#include "gfxModified.h"
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

using namespace std;

//Resolución de la pantalla
#define ANCHURA 800
#define ALTURA 600



int main()
{
    int i, contador;
    char buffer[30];
    char* output;
    struct timeval tv;
    time_t curtime;

    gfx_open(ANCHURA, ALTURA, "Ejemplo gfx_display_ascii");
    gfx_color(46, 68, 94);
    
    while(1) {
        gettimeofday(&tv, NULL); 
        curtime = tv.tv_sec;
        strftime(buffer, 10,"%T", localtime(&curtime));

        output = (char *)malloc(strlen(buffer)+1);
        strcpy(output, buffer);

        gfx_clear();

        gfx_display_ascii(10,   20, 5 , buffer[0]);
        gfx_display_ascii(50,   20, 5 , buffer[1]);
 
        gfx_fill_rectangle(110, 35, 13, 13);
        gfx_fill_rectangle(110, 60, 13, 13);
 
        gfx_display_ascii(150,  20, 5 , buffer[3]);
        gfx_display_ascii(200,  20, 5 , buffer[4]);

        gfx_fill_rectangle(260, 35, 13, 13);
        gfx_fill_rectangle(260, 60, 13, 13);

        gfx_display_ascii(290,  20, 5 , buffer[6]);
        gfx_display_ascii(330,  20, 5 , buffer[7]);

        gfx_flush();
        sleep(1);

    }
    

}


