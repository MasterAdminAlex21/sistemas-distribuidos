a.out: SocketDatagrama.o servidor.cpp PaqueteDatagrama.o LeerDirectorio.o archivos.o
	g++ servidor.cpp SocketDatagrama.o PaqueteDatagrama.o LeerDirectorio.o archivo.o -std=c++0x -o servidor

LeerDirectorio.o: LeerDirectorio.cpp
	g++ LeerDirectorio.cpp -c
archivos.o: archivo.cpp
	g++ archivo.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c

clean:
	rm servidor *.o 
