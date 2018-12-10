#include <iostream>
using namespace std;

class Cliente
{
  private:
    // no class variables
  public:
    Cliente() {cout << "\nNuevo Cliente\n";};
    ~Cliente()
     {cout << "El objeto cliente se ha borrado\n";};
    int getTiempo(){return(1 + rand() % 15);};  
    int getGasolina(){ 
    	int gas=(rand()%13)+3;
    	totalGasolina+=gas;
    	return gas;
    };
    static int totalGasolina;
};

int Cliente::totalGasolina = 0;

int main(){
	Cliente *a;
	srand(time(NULL));
	for( int i = 0; i < 10; i++ ){
		a = new Cliente;
		cout << "El cliente llegó al minuto: " << a->getTiempo()<<"\n";
		cout << "El cliente cargó: " << a->getGasolina()<<" l\n";
		delete a;
	}

	cout << "\nSe cargaron " << a->totalGasolina << " litros\n";
	return 0;
}