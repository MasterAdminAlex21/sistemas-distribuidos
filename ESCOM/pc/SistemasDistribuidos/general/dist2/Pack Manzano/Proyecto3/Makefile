all: cliente servidor
servidor: SocketDatagrama.o servidor.cpp Archivo.o
	g++ servidor.cpp SocketDatagrama.o PaqueteDatagrama.o Archivo.o -o servidor
cliente: SocketDatagrama.o cliente.cpp Archivo.o
	g++ cliente.cpp SocketDatagrama.o PaqueteDatagrama.o Archivo.o -o cliente
Archivo.o: Archivo.cpp Archivo.h
	g++ Archivo.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
