all: receptor emisor
receptor:PaqueteDatagrama.o SocketMulticast.o receptor.cpp
	g++ PaqueteDatagrama.o SocketMulticast.o receptor.cpp -o receptor
emisor: PaqueteDatagrama.o SocketMulticast.o emisor.cpp
	g++ PaqueteDatagrama.o SocketMulticast.o emisor.cpp -o emisor
SocketMulticast.o: PaqueteDatagrama.o SocketMulticast.h SocketMulticast.cpp
	g++ SocketMulticast.cpp -c

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h	
	g++ PaqueteDatagrama.cpp -c
