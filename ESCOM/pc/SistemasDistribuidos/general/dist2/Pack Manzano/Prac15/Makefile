all: cliente cliente2
cliente2: cliente2.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ -pthread cliente2.cpp PaqueteDatagrama.o SocketDatagrama.o -w -o cliente2
cliente: cliente.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ -lpthread cliente.cpp PaqueteDatagrama.o SocketDatagrama.o -w -o cliente

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h	
	g++ PaqueteDatagrama.cpp -c