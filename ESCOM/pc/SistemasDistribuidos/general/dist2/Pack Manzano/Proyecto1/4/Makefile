1: 1.cpp Rectangulo.o
	g++ 1.cpp Rectangulo.o Coordenada.o Ortoedro.o -o run
Ortoedro.o: Rectangulo.o Ortoedro.cpp Ortoedro.h
	g++ Ortoedro.cpp -c
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c