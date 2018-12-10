#include <iostream>
#include <stdlib.h>

using namespace std;


class Elevator{
	private:
	    int elNum;
	    int currentFloor; 
	    int highestFloor;
	public:
		Elevator(int = 1, int = 1, int = 15);
		bool request(int);
};

Elevator::Elevator(int idnum, int cfloor, int maxfloor){
	elNum = idnum;
	currentFloor = cfloor;
	highestFloor = maxfloor;
}

bool Elevator::request(int newfloor){
	if(currentFloor == newfloor)
		return false;
	if (newfloor < 1 || newfloor > highestFloor);
	else if (newfloor > currentFloor){
    	cout << "\nElevator " << elNum
        	<< " starting at floor " << currentFloor << endl;
    	while (newfloor > currentFloor){
      		currentFloor++;
      		cout << " Going Up - now at floor " << currentFloor << endl;
    	}
    	cout << "Elevator " << elNum
        	 << " stopping at floor " << currentFloor << endl;
  	}else{
    	cout << "\nElevator " << elNum
        	<< " starting at floor " << currentFloor << endl;
    	while (newfloor < currentFloor){
      		currentFloor--;
      		cout << " Going Down - now at floor " << currentFloor << endl;
    	}
    	cout << "Elevator " << elNum
       		<< " Stopping at floor " << currentFloor << endl;
  	}
  	return true;
}

int main(){
	srand(time(NULL));
	Elevator a;
	for(int i = 0; i < 5; i++){
		int nextNumber;
		do{ 
			nextNumber = rand() % 15 + 1;
		}while(!a.request(nextNumber));
	}
	return 0;
}