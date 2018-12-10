all: cliente
cliente: cliente.cpp SocketDatagrama.o Header.h
	g++ cliente.cpp SocketDatagrama.o PaqueteDatagrama.o -o cliente
SocketDatagrama.o: SocketDatagrama.h SocketDatagrama.cpp PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.h PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c