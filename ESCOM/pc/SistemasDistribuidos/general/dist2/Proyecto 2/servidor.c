#include <X11/Xlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

unsigned long ObtieneColor(Display* dis, char* color_name)
{
   Colormap cmap;
   XColor color_cercano, color_verdadero;

   cmap = DefaultColormap(dis, 0);
   XAllocNamedColor(dis, cmap, color_name, &color_cercano, &color_verdadero);
   return(color_cercano.pixel);

}

int puerto = 7200;

int main()
{
   Display *disp = NULL;
   Window ventana;
   XColor color;
   int t;

   disp = XOpenDisplay(NULL);
   ventana = XCreateSimpleWindow (disp, XDefaultRootWindow (disp), 100, 100, 800, 600, 1, 1,BlackPixel (disp, DefaultScreen(disp)));
   XMapWindow (disp, ventana);
   int i, j;
   int num[2];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   XSetForeground (disp, XDefaultGC (disp, DefaultScreen(disp)), BlackPixel(disp, 0)^ObtieneColor(disp, "white"));
   while(1) {
      recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      XSetForeground (disp, XDefaultGC (disp, DefaultScreen(disp)), BlackPixel(disp, 0)^ObtieneColor(disp, "white"));
      XDrawPoint (disp,ventana,XDefaultGC (disp, DefaultScreen(disp)),num[0], num[1]);
   }
   XDestroyWindow( disp, ventana);
   XCloseDisplay(disp);

   return(0);
}