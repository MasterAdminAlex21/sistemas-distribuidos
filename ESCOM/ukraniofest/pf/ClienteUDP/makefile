main: main.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ main.cpp -pthread PaqueteDatagrama.o SocketDatagrama.o -o cliente 
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
