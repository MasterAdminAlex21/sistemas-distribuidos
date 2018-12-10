#include "Archivo.h"
using namespace std;

Archivo::Archivo(const char *filename, int banderas){
	nombreArchivo = filename;
	if((fd = open(filename, banderas)) == -1){
		perror(filename);
		exit(-1);
   	}
}
Archivo::Archivo(const char *filename, int banderas, mode_t modo){
	nombreArchivo = filename;
	if((fd = open(filename, banderas, modo)) == -1){
		perror(filename);
		exit(-1);
	}
}

Archivo::~Archivo(){
}

size_t Archivo::lee(size_t nbytes){
	contenido = new char[nbytes];
	return read(fd, contenido, nbytes);
}

size_t Archivo::escribe(const void *buffer, size_t nbytes){
	return write(fd, buffer, nbytes);
}
char *Archivo::get_contenido(){
	return contenido;
}
void Archivo::cerrar(){
	close(fd);
}
vector<int> Archivo::buscaOcurrencia(char* archivo, char* cadena){
	size_t nbytes=100;//numero de bytes a enviar por cada datagrama
        size_t leidos=-1;
        int offset=0;
        int acumulado=0;
        vector<int> v;
        char * buffer;
        string libro;
        int i=0;
        Archivo origen(archivo, O_RDONLY);
        while(leidos!=0){
		leidos = origen.lee(BUFSIZ);
		//cout << leidos << endl;
		buffer = origen.get_contenido();
		//cout << buffer;
		libro = buffer;
		//cout << libro;
	
		while(offset != -1){
		
			
			offset= libro.find(cadena);
			if(offset!=-1){
				acumulado = acumulado + offset;
				v.push_back(acumulado);
				//cout << v[v.size()-1]<< endl;
				libro =libro.substr(offset+strlen(cadena));
				//cout << "ya entre" << i++ << endl;
			}
		}
		offset=0;
 	}	
 	origen.cerrar();
	return v;	
}
vector<string> Archivo::buscaLibros(){
	  /* Con un puntero a DIR abriremos el directorio */
	  DIR *dir;
	  /* en *ent habrá información sobre el archivo que se está "sacando" a cada momento */
	  struct dirent *ent;
	 vector<string> archivos;
	 /* Empezaremos a leer en el directorio actual */
	  dir = opendir ("./LIBROS");

	  /* Miramos que no haya error */
	  if (dir == NULL) 
	    puts("No puedo abrir el directorio");
	  
	  /* Una vez nos aseguramos de que no hay error, ¡vamos a jugar! */
	  /* Leyendo uno a uno todos los archivos que hay */
	  while ((ent = readdir (dir)) != NULL) 
	  {
	      /* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
	      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) )
	    	{
		     // Una vez tenemos el archivo, lo pasamos a una función para procesarlo. 
		     //cout << ent->d_name << endl;
		     archivos.push_back(ent->d_name);
		     //procesoArchivo(ent->d_name);
	    	}
	  }
	  closedir (dir);
	  return archivos;
}
