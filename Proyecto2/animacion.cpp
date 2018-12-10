#include "gfx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
#define PI (3.1415926536)

class Coordenada{
private:
  double x;
  double y;
  double magnitud;
  double angle;
public:
  Coordenada(double = 0, double = 0);
  double obtenerX();
  double obtenerY();
  void imprimeCord();
  double obtenerMagnitud();
  double obtenerAngulo();
  void setMagnitud(Coordenada centro);
};

Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy){
  if(x > 0  && y > 0) angle = (atan(yy/xx) * 360/PI);
  if(x > 0  && y < 0) angle = 180 - (atan(yy/xx) * 360/PI);
  if(x < 0  && y < 0) angle = 270 - (atan(yy/xx) * 360/PI);
  if(x < 0  && y > 0) angle = 270 + (atan(yy/xx) * 360/PI);
}

double Coordenada::obtenerX(){
  return x;
}

double Coordenada::obtenerY(){
  return y;
}

void Coordenada::imprimeCord(){
  cout << "X: " << x << endl;
  cout << "Y: " << y << endl;
}

double Coordenada::obtenerMagnitud(){
  return magnitud;
}

double Coordenada::obtenerAngulo(){
  return angle;
}

void Coordenada::setMagnitud(Coordenada centro){
  double x,y;
  x = pow(centro.obtenerX() - x, 2);
  y = pow(centro.obtenerY() - y, 2);
  magnitud = sqrt(x + y);
}

/***********************************************************/

class PoligonoIrreg{
private:
  vector<Coordenada> v;
  int vertices;
  Coordenada centro;
public:
  PoligonoIrreg(int numC);
  void agregarCord(Coordenada);
  void imprimeCord();
  void ordenaA();
  int getVertices();
  void paint();
  void setCentro(Coordenada c);
  Coordenada getCentro();
  static int vecesVer;
};

void PoligonoIrreg::paint(){
  Coordenada c1, c2;
  for(int t = 0; t < v.size(); t++){
    c1 = v[t];
    c2 = v[t + 1];
    gfx_line(2 * centro.obtenerX() + c1.obtenerX(), 2 * centro.obtenerY() + c1.obtenerY(), 2 * centro.obtenerX() + c2.obtenerX(), 2 * centro.obtenerY() + c2.obtenerY());
    gfx_flush();
    sleep(1);
  }
  c1 = v[v.size()];
  c2 = v[0];
  gfx_line(2 * centro.obtenerX() + c1.obtenerX(), 2 * centro.obtenerY() + c1.obtenerY(), 2 * centro.obtenerX() + c2.obtenerX(), 2 * centro.obtenerY() + c2.obtenerY());
}

int PoligonoIrreg::vecesVer = 0;

PoligonoIrreg::PoligonoIrreg(int numC){
  v.reserve(numC);
  vertices = 0;
}

void PoligonoIrreg::setCentro(Coordenada c){
  centro = c;
}

void PoligonoIrreg::agregarCord(Coordenada c){
  v.push_back(c);
  vecesVer++;
  vertices++;
}

void PoligonoIrreg::imprimeCord(){
  cout << "Vertices: " << vertices << endl;
  for(unsigned int i=0; i < vertices; i++){
    v[i].imprimeCord();
    cout << "Angulo del vertice " << i << ": " << v[i].obtenerAngulo() << endl;
	}
  cout << endl;
}

void PoligonoIrreg::ordenaA(){
  int n = vertices;
  Coordenada aux;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n-i-1; j++){
      if (v[j].obtenerAngulo() > v[j+1].obtenerAngulo()){
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
  }
}

int PoligonoIrreg::getVertices(){
  return vertices;
}

/***********************************************************/

int main(){
  char c;
  int n = 5; //Numero de asteroides
  int m = 25; //Numero de vertices
  double randomX;
  double randomY;
  vector<PoligonoIrreg> asteroides;

  asteroides.reserve(n);
  srand(time(NULL));
  srand48(time(NULL));
  Coordenada centro(drand48() * (100.0 + 100.0), drand48() * (100.0 + 100.0));

  //Creación de n vertices con a lo mas m vertices
  for (int i = 0; i < n; ++i){
    int r = rand() % m;
    PoligonoIrreg Poligono(r);
    Poligono.setCentro(centro);
    for (int e = 0; e < (r-1); ++e){
       randomX = drand48() * (100.0 + 100.0) - 100.00;
       randomY = drand48() * (100.0 + 100.0) - 100.00;
  	   Coordenada cord1(randomX, randomY);
       cord1.setMagnitud(centro);
  		 Poligono.agregarCord(cord1);
  	}
    Poligono.ordenaA();
    asteroides[0].imprimeCord();
  	asteroides.push_back(Poligono);
  }

  gfx_open(800, 600, "Erick Sanchez Jose");
  gfx_color(0,200,100);

  while (1) {
    for(int i = 0; i < asteroides.size(); i++){
      asteroides[0].paint();
    }
    c = gfx_wait();
    if(c == 'q') break;
  }
  return 0;
}
