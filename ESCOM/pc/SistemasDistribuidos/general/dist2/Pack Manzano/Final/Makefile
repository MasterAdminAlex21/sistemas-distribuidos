all: servidor
servidor: servidor.cpp SocketMulticast.o SocketDatagrama.o PaqueteDatagrama.o Archivo.o
	g++ -lpthread servidor.cpp SocketMulticast.o SocketDatagrama.o Archivo.o PaqueteDatagrama.o -o servidor -w

SocketMulticast.o: PaqueteDatagrama.o SocketMulticast.h SocketMulticast.cpp
	g++ SocketMulticast.cpp -c

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h	
	g++ PaqueteDatagrama.cpp -c

Archivo.o: Archivo.h Archivo.cpp
	g++ Archivo.cpp -c