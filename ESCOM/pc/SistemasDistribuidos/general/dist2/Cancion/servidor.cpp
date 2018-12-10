#include "SocketDatagrama.h"
#include <sys/time.h>
#include <set>
#include <utility>

using namespace std;

int puerto = 7200;

int main(void){
   SocketDatagrama sock(7200);
   set< pair<string, int> > disponibles;
   int lastPosition = 0;
   struct timeval tv;
   time_t timeA, timeB;
   gettimeofday(&tv, NULL);
   timeB = tv.tv_sec;
   int REPRODUCE = 0;
   int* num = new int[2];
   char ip[16];

   while(1) {
      gettimeofday(&tv, NULL);
      timeA = tv.tv_sec;
      if(timeA != timeB){
         timeB = timeA;
         if(!REPRODUCE && disponibles.size() > 0){
            num[0] = lastPosition;
            num[1] = 1;
            string a = disponibles.begin() -> first;
            for(int i = 0; i < 16; i++)
               ip[i] = 0;
            for(int i = 0; i < a.size(); i++)
               ip[i] = a[i];
            PaqueteDatagrama env((char *)num, 8, ip, disponibles.begin() ->second);
            sock.envia(env);
         }
         disponibles.clear();
      }
      PaqueteDatagrama aux(8);
      sock.recibe(aux);
      int *datos =(int *) aux.obtieneDatos();
      std :: cout << datos[0] << " " << datos[1] << std :: endl; 
      lastPosition = max(lastPosition, datos[0]);
      if(datos[1] == 0){
         string a = aux.obtieneDireccion();
         disponibles.insert(make_pair(a, aux.obtienePuerto()));
      }
      PaqueteDatagrama eco((char *) datos, 4, aux.obtieneDireccion(), aux.obtienePuerto());
      sock.envia(eco);
   }
}

