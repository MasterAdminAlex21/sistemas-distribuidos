uvideojuego:  uvideojuego.o gfxModified.o
	g++ Eduardo_Perez_Gomez_DSD_4CM3_2.o gfxModified.o -o vj -lX11 -lm
uvideojuego.o: Eduardo_Perez_Gomez_DSD_4CM3_2.cpp gfxModified.o
	g++ Eduardo_Perez_Gomez_DSD_4CM3_2.cpp -c
gfxModified.o: gfxModified.c gfxModified.h
	gcc gfxModified.c -c
clean:
	rm vj uvideojuego.o gfxModified.o
