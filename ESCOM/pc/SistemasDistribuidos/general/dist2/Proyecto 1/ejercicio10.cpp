#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


class Customer{
	private:
		int arrivalTime;
		int gas;
		int type;
	public:
		Customer();
		void showDatas();
		int getGas();
		int getArrivalTime();
		int getType();
};

Customer :: Customer(){
	arrivalTime = rand() %15 + 1;
	gas = rand() % 13 + 3;
	type = rand() % 3;
}

void Customer :: showDatas(){
	cout << "gas: " << gas << endl;
	cout << "arrival time: " << arrivalTime << endl;
	if(type == 0)
		cout << "Type of gas is: 87 octane" << endl << endl;
	if(type == 1)
		cout << "Type of gas is: 93 octane" << endl << endl;
	if(type == 2)
		cout << "Type of gas is: 97 octane" << endl << endl;
	
}

int Customer :: getGas(){
	return gas;
}

int Customer :: getArrivalTime(){
	return arrivalTime;
}

int Customer :: getType(){
	return type;
}

int main(){
	srand(time(NULL));
	vector <int> sumGas(3);
	for(int i = 0; i < 10; i++){
		Customer aux;
		aux.showDatas();
		sumGas[aux.getType()] += aux.getGas();
	}
	cout << "Total of 87 octane: " << sumGas[0] << endl;
	cout << "Total of 93 octane: " << sumGas[1] << endl;
	cout << "Total of 97 octane: " << sumGas[2] << endl;
	return 0;
}