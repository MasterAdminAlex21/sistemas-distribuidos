#include <iostream>
#include <map>
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
    int getTipo(){
      return rand() % 3;
    };
    int getGasolina( int tipo ){ 
      int gas=(rand()%13)+3;
      total[tipo] +=gas;
      return gas;
    };
    static map< int, int > total;

};

map< int, int > Cliente::total;

int main(){
  int gas[3];
  gas[0] = 87;
  gas[1] = 93;
  gas[2] = 97;
  int tipo;
	Cliente *a;
	srand(time(NULL));
	for( int i = 0; i < 10; i++ ){
		a = new Cliente;
		cout << "El cliente llegó al minuto: " << a->getTiempo()<<"\n";
    tipo = a->getTipo();
    cout << "El cliente cargó gasolina de: "<< gas[tipo] << " octanos\n" ;
		cout << "El cliente cargó: " << a->getGasolina(tipo)<<"l\n";
		delete a;
	}

	cout << "\nSe cargaron " << a->total[0] << " litros de gasolina de 87 octanos\n";
  cout << "Se cargaron " << a->total[1] << " litros de gasolina de 93 octanos\n";
  cout << "Se cargaron " << a->total[2] << " litros de gasolina de 97 octanos\n";
	return 0;
}