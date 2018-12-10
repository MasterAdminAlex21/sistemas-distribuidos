#ifndef PAR_H_
#define PAR_H_
class Par
{
private:
	int numero;
	bool esPrimo;
public:
	Par( int = 1 , bool = true );
	int getNumero();
	bool isPrimo();
	void setIsPrimo( bool );
	void setNumero( int );
};
#endif