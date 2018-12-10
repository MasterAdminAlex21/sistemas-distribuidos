all: servidor cliente
servidor: Archivo.o servidor.cpp
	g++ servidor.cpp Archivo.o -o servidor
cliente: Archivo.o cliente.cpp
	g++ cliente.cpp Archivo.o -o cliente
Archivo.o: Archivo.h Archivo.cpp
	g++ Archivo.cpp -c