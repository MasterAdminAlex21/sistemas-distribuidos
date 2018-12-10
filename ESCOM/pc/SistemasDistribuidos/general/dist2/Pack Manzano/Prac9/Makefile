4: 4.cpp PoligonoReg.o
	g++ 4.cpp Coordenada.o PoligonoReg.o PoligonoIrreg.o -o 4
PoligonoReg.o: PoligonoReg.cpp PoligonoReg.h PoligonoIrreg.o
	g++ PoligonoReg.cpp -c
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c