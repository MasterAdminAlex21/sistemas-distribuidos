
#include "SocketDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <thread>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;
int port1 = 0, port2 = 0, n = 0;

void threadMinusculas(int n);
void threadMayusculas(int n);
int compareStrings(const void *pStr1, const void *pStr2);

SocketDatagrama socket1(8080);
SocketDatagrama socket2(8081);

int main(int argc, char* argv[])
{
  if (argc != 2) {
    cout << "\n\tNot enough arguments\n\n" << endl;;
    return 1;
  }

  n = atoi(argv[1]);

  thread thrLowercase(threadMinusculas, n);
  sleep(1);
  thread thrUppercase(threadMayusculas, n);

  thrLowercase.join();
  thrUppercase.join();

  return 0;
}


void threadMinusculas(int n)
{
  char** ordenados = (char **)malloc(sizeof(char *) * n);
  char* ip;
  int puerto = 0;

  for (int i = 0; i < n; i++) {
    PaqueteDatagrama pq1(3*sizeof(char));
    socket1.recibe(pq1);
    char * cadena = (char *)malloc(3*sizeof(char));
    ordenados[i] = (char *)malloc(3*sizeof(char));
    cadena = pq1.obtieneDatos();
    strcpy(ordenados[i], cadena);
    printf("SERVER Lowercase[%d] = %s \n", i, cadena);

    ip = pq1.obtieneDireccion();
    puerto = pq1.obtienePuerto();
  }

  qsort(ordenados, n, sizeof(char *), compareStrings);
  char * res = (char *)malloc(3*sizeof(char)*n + (n+1));

  for (int i = 0; i < n; i++) {
    printf("SERVER SORTED LOWER[%d] = %s \n", i, ordenados[i]);
    strcat(res, ordenados[i]);
    strcat(res, ",");
  }

  printf("to client s1: %s", res);
  PaqueteDatagrama p((char*)res, 100, ip, puerto);
  socket1.envia(p);
}


void threadMayusculas(int n)
{
  char** ordenados = (char **)malloc(sizeof(char *) * n);
  char* ip;
  int puerto = 0;

  for (int i = 0; i < n; i++) {
    PaqueteDatagrama pq2(3*sizeof(char));
    socket2.recibe(pq2);
    char * cadena = (char *)malloc(3*sizeof(char));
    ordenados[i] = (char *)malloc(3*sizeof(char));

    cadena = pq2.obtieneDatos();
    ip = pq2.obtieneDireccion();
    puerto = pq2.obtienePuerto();

    strcpy(ordenados[i], cadena);
    printf("SERVER Uppercase[%d] = %s \n", i, cadena);
  }

  qsort(ordenados, n, sizeof(char *), compareStrings);
  char * res = (char *)malloc(3*sizeof(char)*n + (n+1));

  for (int i = 0; i < n; i++) {
    printf("SERVER SORTED UPPER[%d] = %s \n", i, ordenados[i]);
    strcat(res, ordenados[i]);
    strcat(res, ",");
  }

  printf("to client s2: %s", res);

  PaqueteDatagrama p((char*)res, 100, ip, puerto);
  socket2.envia(p);
}



int compareStrings(const void *pStr1, const void *pStr2)
{
     return strcmp(*(char **)pStr1, *(char **)pStr2);
}
