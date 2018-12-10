all: cl se
cl: clT.cpp SocketDatagrama.o PaqueteDatagrama.o Solicitud.o
	g++ clT.cpp SocketDatagrama.o PaqueteDatagrama.o Solicitud.o -o cl
se: seT.cpp SocketDatagrama.o PaqueteDatagrama.o Respuesta.o
	g++ seT.cpp SocketDatagrama.o PaqueteDatagrama.o Respuesta.o -o se
Solicitud.o: Solicitud.cpp Solicitud.h
	g++ Solicitud.cpp -c
Respuesta.o: Respuesta.cpp Respuesta.h
	g++ Respuesta.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
