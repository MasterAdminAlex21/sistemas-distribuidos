#ifndef CIRCULO_H_
#define CIRCULO_H_
class Circulo
{
private:
	int x, y;
	double radio;
	static double escala;
public:
	Circulo(int = 0 , int = 0, double = 0.0);
	static void setEscala( double );
	static void imprimeEscala();
	void imprimeCirculo();
};
#endif