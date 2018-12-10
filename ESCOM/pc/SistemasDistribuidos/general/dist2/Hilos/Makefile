a.out: SocketDatagrama.o broadcastSort.cpp
	g++ broadcastSort.cpp SocketDatagrama.o PaqueteDatagrama.o -pthread
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
