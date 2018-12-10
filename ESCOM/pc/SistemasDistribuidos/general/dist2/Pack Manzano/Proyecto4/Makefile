all: servidor reportes
servidor: servidor.cpp SocketDatagrama.o PaqueteDatagrama.o Archivo.o Generador.o
	g++ servidor.cpp SocketDatagrama.o PaqueteDatagrama.o Archivo.o Generador.o -o servidor
reportes: reportes.cpp Archivo.o Generador.o
	g++ reportes.cpp Archivo.o Generador.o SocketDatagrama.o PaqueteDatagrama.o -o reportes
Generador.o: Generador.cpp Generador.h SocketDatagrama.o PaqueteDatagrama.o
	g++ Generador.cpp -c	
Archivo.o: Archivo.h Archivo.cpp
	g++ Archivo.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
