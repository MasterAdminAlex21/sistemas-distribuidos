
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <arpa/inet.h>
#include <fstream>
#include <dirent.h>
#include "stdc++.h"
using namespace std;
int b[101010], socket_id, addr_len, long_query;
struct sockaddr_in servidor , cliente;
string T, P, Y;
// pre procesamiento y construccion de la funcion de regresión.
void kmpPreprocess() { 
  T = Y;
  // casos base.
  b[0] = b[1] = 0; 
  int i, j, m = P.size();
    for(i = 2; i <= m; i++){
      // maximo borde hasta i-1 sin considerar al caracter i
      j = b[i - 1];
      for( ; ; ) {
        if(P[j] == P[i - 1]){
          b[i] = j + 1; 
          break; 
        }
        if(j == 0){
          b[i] = 0; 
          break; 
        }
        j = b[j];
      }
    }   
}
//dada la función de regresión verifica ocurrencias.
// y almacena posiciones en un vector.
vector<int> kmpSearch(){
  vector<int>V;
  kmpPreprocess();
  T = Y;
  int n = T.size(),  m = P.size(), i = 0 , j = 0;
  for( ; ; ) {
    if(i == n) break;
      if(T[i] == P[j]) {
        i++, j++; 
      // ocurrencia en i - j
      if(j == m){
        V.push_back( i - j);
      }
    }else{
      if(j > 0)
        j = b[j];
      else 
        i++;
    }
  }
  return V;
}
//funcion que regresa el nombre de los archivos dentro de la carpeta libros.
vector<string> listFile(){
  vector<string> ans;
  DIR *dir;
  struct dirent *M;
  if((dir = opendir("LIBROS/"))){
    while((M = readdir(dir))) if( strcmp(M->d_name, ".") != 0 && strcmp(M->d_name, "..") != 0 ) ans.push_back(M->d_name);
      closedir(dir);
  }
  return ans;
}
void creaServer(){
  socket_id = socket(AF_INET, SOCK_DGRAM, 0);
  servidor.sin_family = AF_INET;
  servidor.sin_port = htons(5000);
  servidor.sin_addr.s_addr = INADDR_ANY;
  bzero(&(servidor.sin_zero), 8);
  bind(socket_id,(struct sockaddr *)&servidor,  sizeof(struct sockaddr));
  addr_len = sizeof(struct sockaddr);
}
int main(){
  //obtencion de archivos 
  vector<string> fx = listFile();
  string finalanswer = "";
  char busqueda[(1 << 10)], resultado[(1 << 10)];
  creaServer();
  fflush(stdout);
  int count = 0,i;
  while (1){
    finalanswer = "";
    cout << "ESPERANDO CADENA..." << endl;
    long_query = recvfrom(socket_id, busqueda, (1 << 10) , 0 , (struct sockaddr *)&cliente, (unsigned int *) &addr_len);
    busqueda[long_query] = '\0';
    cout << "La palabra buscada: " << busqueda << endl;
    string PP(busqueda);
    P = PP;
    for(int i = 0; i < fx.size(); i++){
      if(fx[i].find("txt") != -1){
        ifstream t("LIBROS/" + fx[i]);
        stringstream buffer;
        buffer << t.rdbuf();
        Y = buffer.str();
        finalanswer += "\t" + fx[i] + "\n";
        vector<int> dx = kmpSearch();
        finalanswer += "offset = ";
        for(int j = 0; j < dx.size(); j++){
          finalanswer += to_string(dx[j]);
          if(j < dx.size() -1)
            finalanswer += ", ";
          }
          finalanswer += "\n";
        }
    }
    strcpy(resultado, finalanswer.c_str());
    sendto(socket_id, resultado, strlen(resultado), 0 , (struct sockaddr *)&cliente,sizeof(struct sockaddr));
    fflush(stdout);
  }
  return 0;
}