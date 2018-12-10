#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[]){
 char buffer[3000], *ocurre;
 int offset, origen;
 if(argc != 3){
 printf("Forma de uso: %s archivo_origen offset\n", argv[0]);
 exit(1);
 }
 if((origen = open(argv[1], O_RDONLY)) == -1){
 perror(argv[1]);
 exit(-1);
 }
 offset = atoi(argv[2]);
 lseek(origen, (off_t)offset, SEEK_SET);
 read(origen, buffer, sizeof buffer);
 ocurre = strstr(buffer, ".\n");
 *(ocurre+1) = '\0';
 printf("El contenido es: <%s>\n", buffer);
}