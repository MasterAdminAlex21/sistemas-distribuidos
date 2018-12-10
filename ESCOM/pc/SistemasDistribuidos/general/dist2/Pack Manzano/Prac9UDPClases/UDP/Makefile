servidor: SocketDatagrama.o cliente.cpp
	g++ servidor.cpp SocketDatagrama.o PaqueteDatagrama.o -o servidor
cliente: SocketDatagrama.o cliente.cpp
	g++ cliente.cpp SocketDatagrama.o PaqueteDatagrama.o -o cliente
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
