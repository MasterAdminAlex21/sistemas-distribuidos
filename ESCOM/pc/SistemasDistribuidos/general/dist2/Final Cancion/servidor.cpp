#include "SocketDatagrama.h"
#include <sys/time.h>
#include <set>
#include <utility>

using namespace std;

int puerto = 7200;
int REPRODUCE;

SocketDatagrama sock(7200);
set< pair<string, int> > disponibles;


int lastPosition = 0;
struct timeval tv;
time_t timeA, timeB;


int* num = new int[2];

char ip[16];

void* Cambio(void*);

int main(void){
  
   pthread_t th1;
   pthread_create(&th1, NULL, &Cambio, NULL);

   while(1) {
      PaqueteDatagrama aux(8);
      sock.recibe(aux);
      int *datos =(int *) aux.obtieneDatos();
      // Posicion sonada
      lastPosition = max(lastPosition, datos[0]);
      cout << "Pos :: " << lastPosition << endl;
      if(datos[1] == 0){ // Este cliente no reproduce
         string a = aux.obtieneDireccion();
         disponibles.insert(make_pair(a, aux.obtienePuerto()));
      }else{
         REPRODUCE = 1;
      }
   }
}


void* Cambio(void*){
   gettimeofday(&tv, NULL);
   timeB = tv.tv_sec;
  
   while(true){
      gettimeofday(&tv, NULL);
      timeA = tv.tv_sec;
      if(timeA - timeB > 1){ // tiempo de lapso un segundo
         timeB = timeA;
         if(!REPRODUCE && disponibles.size() > 0){ // si nadie reproduce tengo que poner a uno disponible
            num[0] = lastPosition;
            num[1] = 1;
            string a = disponibles.begin() -> first;
            for(int i = 0; i < 16; i++)
               ip[i] = 0;
            for(int i = 0; i < a.size(); i++)
               ip[i] = a[i];
            cout << num[0] << " " << num[1] << endl;
            PaqueteDatagrama env((char *)num, 8, ip, disponibles.begin() ->second);
            sock.envia(env);
         }
         disponibles.clear();
         REPRODUCE = 0;
      }
   }
}
