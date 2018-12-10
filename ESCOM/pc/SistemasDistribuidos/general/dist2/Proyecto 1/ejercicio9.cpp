#include <iostream>
#include <stdlib.h>

using namespace std;


class Customer{
	private:
		int arrivalTime;
		int gas;
	public:
		Customer();
		void showDatas();
		int getGas();
		int getArrivalTime();
};

Customer :: Customer(){
	arrivalTime = rand() %15 + 1;
	gas = rand() % 13 + 3;
}

void Customer :: showDatas(){
	cout << "gas: " << gas << endl;
	cout << "arrival time: " << arrivalTime << endl << endl;

}

int Customer :: getGas(){
	return gas;
}

int Customer :: getArrivalTime(){
	return arrivalTime;
}

int main(){
	srand(time(NULL));
	for(int i = 0; i < 10; i++){
		Customer aux;
		aux.showDatas();
	}
	return 0;
}