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
#include <bits/stdc++.h>
using namespace std;
int b[101010];
string T, P, Y;
void naiveStringMatching(string A, string B){
  int N = A.size();
  int M = B.size();
  for(int i = 0; i < N; i++){
    int f = 1;
    for(int j = 0; j < M && f; j++)
      if(i + j >= N || A[i + j] != B[j])
        f = 0;
    if(f)
      cout << "encontrado en: " << i << endl;
  }
}

int main(){
  int sock;
  int addr_len, bytes_read;
  char recv_data[1024],send_data[1024];
  struct sockaddr_in server_addr , client_addr;
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(5000);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  bzero(&(server_addr.sin_zero), 8);
  bind(sock,(struct sockaddr *)&server_addr,  sizeof(struct sockaddr));
  addr_len = sizeof(struct sockaddr);
  int count = 0;
  bytes_read = recvfrom(sock,recv_data,1024,0,(struct sockaddr *)&client_addr,(unsigned int *) &addr_len);
  recv_data[bytes_read] = '\0';
  printf("%s\n", recv_data);
  DIR * midirectorio;
  struct dirent *entry;
  if((midirectorio = opendir("CARPETA/"))){
    while((entry = readdir(midirectorio))){
        string nombre(entry->d_name);
        cout << nombre << endl;
        ifstream flujo("CARPETA/" + nombre);
        stringstream mf;
        mf << flujo.rdbuf();
        naiveStringMatching(mf.str(), "ecuánime");
    }
  }
  strcpy(send_data, "LOL");
  sendto(sock,send_data,strlen(send_data),0,(struct sockaddr *)&client_addr,sizeof(struct sockaddr));
  fflush(stdout);
  
  return 0;
}