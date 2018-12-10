2: 2.cpp Rectangulo.o PoligonoIrreg.o
	g++ 2.cpp Rectangulo.o Coordenada.o PoligonoIrreg.o -o 2
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c