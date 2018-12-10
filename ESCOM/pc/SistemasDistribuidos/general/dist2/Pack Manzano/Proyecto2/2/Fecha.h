#ifndef FECHA_H_
#define FECHA_H_
#include <string>
using namespace std;
class Fecha
{
private:
	long aaaammdd;
public:
	Fecha(int = 3, int = 4, int = 2014);
	Fecha(long);
	void inicializaFecha(int, int, int);
	void muestraFecha();
};
#endif