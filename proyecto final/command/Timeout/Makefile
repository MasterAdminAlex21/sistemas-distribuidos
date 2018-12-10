Servidor: Servidor.o SocketDatagrama.o PaqueteDatagrama.o Respuesta.o
	g++ Servidor.o SocketDatagrama.o PaqueteDatagrama.o Respuesta.o -o Servidor
Cliente: Cliente.o SocketDatagrama.o PaqueteDatagrama.o Solicitud.o Palindromo.o
	g++ Cliente.o SocketDatagrama.o PaqueteDatagrama.o Solicitud.o Palindromo.o -o Cliente
Servidor.o: Servidor.cpp
	g++ Servidor.cpp -c -Wall
Cliente.o: Cliente.cpp
	g++ Cliente.cpp -c -Wall
Respuesta.o: Respuesta.cpp Respuesta.h Mensaje.h
	g++ Respuesta.cpp -c -Wall
Solicitud.o: Solicitud.cpp  Solicitud.h Mensaje.h
	g++ Solicitud.cpp -c -Wall
SocketDatagrama.o: SocketDatagrama.cpp  SocketDatagrama.h 
	g++ SocketDatagrama.cpp -c -Wall
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h 
	g++ PaqueteDatagrama.cpp -c -Wall
Palindromo.o: Palindromo.cpp Palindromo.h 
	g++ Palindromo.cpp -c -Wall
clear:
	rm *.o Servidor Cliente