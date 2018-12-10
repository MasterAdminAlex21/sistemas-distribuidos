#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_
class Temperatura
{
private:
	double kelvin;
public:
	void setTempKelvin( double );
	void setTempFahrenheit( double );
	void setTempCelsius( double );
	void imprimeKelvin();
	void imprimeFahrenheit();
	void imprimeCelsius();
};
#endif