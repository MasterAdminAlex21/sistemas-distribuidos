cliente.out: SocketDatagrama.o header.h cliente.cpp
	g++ cliente.cpp -o cliente SocketDatagrama.o PaqueteDatagrama.o
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
