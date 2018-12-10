a.out: SocketDatagrama.o servidor.cpp
	g++ servidor.cpp SocketDatagrama.o PaqueteDatagrama.o
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c