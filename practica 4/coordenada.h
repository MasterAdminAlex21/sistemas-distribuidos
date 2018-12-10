#ifndef _Coordenada_
#define _Coordenada_

class Coordenada{
private:
 double x;
 double y;
public:
 Coordenada(double =0, double=0 );
 double obtenerx();
 double obtenery();
}

#endif

Coordenada::Coordenada(double xx,double yy):x(xx),y(yy)
{ }

double Coordenada::obtenerx(){
 return x;
}

double Coordenada::obtenery(){
 return y;
}