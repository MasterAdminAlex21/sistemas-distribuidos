server: SocketDatagrama.o PaqueteDatagrama.o
	g++ server.cpp SocketDatagrama.o PaqueteDatagrama.o -o server
client: SocketDatagrama.o PaqueteDatagrama.o
	g++ client.cpp SocketDatagrama.o PaqueteDatagrama.o -o client
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
