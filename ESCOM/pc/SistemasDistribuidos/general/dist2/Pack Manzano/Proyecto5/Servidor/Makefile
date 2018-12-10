all: servidor
servidor: Servidor.o multiples.cpp
	g++ multiples.cpp Servidor.o Archivo.o Generador.o SocketDatagrama.o PaqueteDatagrama.o -o servidor
Servidor.o: Generador.o SocketDatagrama.o Servidor.h Servidor.cpp
	g++ Servidor.cpp -c
Generador.o: Generador.h Generador.cpp Archivo.o
	g++ Generador.cpp -c
Archivo.o: Archivo.h Archivo.cpp
	g++ Archivo.cpp -c
SocketDatagrama.o: SocketDatagrama.h SocketDatagrama.cpp PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.h PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c