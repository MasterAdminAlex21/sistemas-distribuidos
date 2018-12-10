#include <iostream>
#include<time.h>
using namespace std;
// class declaration section
class Elevator
{
  private:
    int elNum;
    int currentFloor; 
    int highestFloor;
  public:
    Elevator(int = 1, int = 1, int = 15);  // constructor
    void request(int);
};
// class implementation section
Elevator::Elevator(int idnum, int cfloor, int maxfloor)
{
  elNum = idnum;
  currentFloor = cfloor;
  highestFloor = maxfloor;
}
void Elevator::request(int newfloor)
{
 if (newfloor < 1 || newfloor > highestFloor || newfloor == currentFloor)
    ;  // do nothing
  else if (newfloor > currentFloor) // move elevator up
  {
    cout << "\nElevator " << elNum
         << " starting at floor " << currentFloor << endl;
    while (newfloor > currentFloor)
    {
      currentFloor++; // add one to current floor
      cout << " Going Up - now at floor " << currentFloor << endl;
    }
    cout << "Elevator " << elNum
         << " stopping at floor " << currentFloor << endl;
  }
  else // move elevator down
  {
    cout << "\nElevator " << elNum
         << " starting at floor " << currentFloor << endl;
    while (newfloor < currentFloor)
    {
      currentFloor--;   // subtract one from current floor
      cout << " Going Down - now at floor " << currentFloor << endl;
    }
    cout << "Elevator "<< elNum
         << " Stopping at floor " << currentFloor << endl;
  }
  return;
}
int main()
{
  srand(time(NULL));
  Elevator a;   // declare 1 object of type Elevator
  int cont=0,val,valant=0;
  while(cont!=5){
    val=(rand()%15)+1;
    while(val==valant){
      val=(rand()%15)+1;
    }
      a.request(val);
      valant=val;
      cont+=1;
  }
  return 0;
}
