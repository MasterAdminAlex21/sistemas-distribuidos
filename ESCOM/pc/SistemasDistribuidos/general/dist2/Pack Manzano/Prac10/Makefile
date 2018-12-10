cliente: cliente.cpp PaqueteDatagrama.o SocketDatagrama.o Archivo.o
	g++ cliente.cpp PaqueteDatagrama.o SocketDatagrama.o Archivo.o -o cliente

Archivo.o: Archivo.cpp Archivo.h
	g++ Archivo.cpp -c

SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c

PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h	
	g++ PaqueteDatagrama.cpp -c