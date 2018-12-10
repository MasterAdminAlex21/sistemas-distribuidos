test: SocketMulticast.o PaqueteDatagrama.o
	g++ emisor.cpp SocketMulticast.o PaqueteDatagrama.o -fPIC -o EMI
	g++ receptor.cpp SocketMulticast.o PaqueteDatagrama.o -fPIC -o REC

SocketMulticast.o: SocketMulticast.cpp SocketMulticast.h PaqueteDatagrama.o
	g++ SocketMulticast.cpp -c -fPIC
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c -fPIC

clean:
	rm SocketMulticast.o PaqueteDatagrama.o
