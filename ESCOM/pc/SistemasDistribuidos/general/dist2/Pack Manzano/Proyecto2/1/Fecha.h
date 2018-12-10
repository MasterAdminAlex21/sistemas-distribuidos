#ifndef FECHA_H_
#define FECHA_H_
#include <string>
using namespace std;
class Fecha
{
private:
	int dia;
	int mes;
	int anio;
	string dias[7];
public:
	Fecha(int = 3, int = 4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
	bool leapyr();
	string dayOfWeek();
};
#endif