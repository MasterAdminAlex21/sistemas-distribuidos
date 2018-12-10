
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

using namespace std;

void threadMinusculas(int n);
void threadMayusculas(int n);

char *ip1, *ip2;
int port1 = 0, port2 = 0, n = 0;
SocketDatagrama s(6666);

int main(int argc, char* argv[])
{
    if (argc != 6) {
        cout << "\n\tNot enough arguments\n\n" << endl;
        return 1;
    }

    ip1 = argv[1];
    ip2 = argv[3];
    port1 = atoi(argv[2]);
    port2 = atoi(argv[4]);
    n = atoi(argv[5]);

    cout << "\nServer[1] -> " << ip1 << ":" << port1 << endl;
    cout << "\nServer[2] -> " << ip2 << ":" << port2 << endl;

    cout << "\nNUM: " << n << endl;

    srand(time(NULL));

    thread thrLowecase(threadMinusculas, n);

    usleep(1000);

    thread thrUppercase(threadMayusculas, n);

    thrLowecase.join();
    thrUppercase.join();
}

void threadMinusculas(int n)
{
  for (int i = 0; i < n; i++) {
    char *stringlower=(char *)malloc(4*sizeof(char));

    for(int j = 0; j < 3; j++) {
      int x = 97 + (rand()%25);
      stringlower[j] = 97+(rand()%25);
      //printf("x = %d\n", x);
    }
    stringlower[3] = '\0';

    PaqueteDatagrama p(stringlower, 4*sizeof(char), ip1, 8080);
    s.envia(p);
    printf("CLIENT Lowercase[%d] = %s enviado!\n", i, stringlower);
  }

  char* ordenados = (char *)malloc(3*sizeof(char)*n + (n+1));;
  PaqueteDatagrama pq1(100);
  s.recibe(pq1);

  ordenados = pq1.obtieneDatos();

  printf("Resultado LOWER: %s", ordenados);
}

void threadMayusculas(int n)
{
  for (int i = 0; i < n; i++) {
    char *stringupper=(char *)malloc(4*sizeof(char));

    for(int j = 0; j < 3; j++) {
      int x = 65 + (rand()%25);
      stringupper[j] = x;
      //printf("x = %d\n", x);
    }
    stringupper[3] = '\0';

    PaqueteDatagrama p(stringupper, 4*sizeof(char), ip2, 8081);
    s.envia(p);
    printf("CLIENT Uppercase[%d] = %s enviado!\n", i, stringupper);
  }

  char* ordenados = (char *)malloc(3*sizeof(char)*n + (n+1));;
  PaqueteDatagrama pq2(100);
  s.recibe(pq2);

  ordenados = pq2.obtieneDatos();

  printf("Resultado UPPEr: %s", ordenados);
}
