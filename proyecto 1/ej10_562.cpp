#include<iostream>
#include<time.h>
using namespace std;

class Customer{
private:
 int reqgas;
 int time;
 static int totalgasA;
 static int totalgasB;
 static int totalgasC;
public:
 Customer();
 ~Customer();//el libro tiene como destructor el signo -, cuando en realidad se usa el ~
 void request();
 static void total();
};

int Customer::totalgasA=0;
int Customer::totalgasB=0;
int Customer::totalgasC=0; 

Customer::Customer(){
 cout<<"A customer has arrived!!!"<<endl;
}

Customer::~Customer(){
 cout<<"the customer has left"<<endl;
}

void Customer::request(){ 
 reqgas=(3+rand())%15;
 time=(1+rand())%15;
 int type=(1+rand())%4;
 switch(type){
  case 1:
   cout<<"the customer request "<<reqgas<<" gallons of 87 octane gas, in "<<time<<" minutes."<<endl;
   totalgasA+=reqgas;
  break;
  case 2:
   cout<<"the customer request "<<reqgas<<" gallons of 93 octane gas, in "<<time<<" minutes."<<endl;
   totalgasB+=reqgas;
  break;
  case 3:
   cout<<"the customer request "<<reqgas<<" gallons of 97 octane gas, in "<<time<<" minutes."<<endl;
   totalgasC+=reqgas;
  break;
 }
}

void Customer::total(){
 cout<<"total 87 octane gas dispatched: "<<totalgasA<<endl;
 cout<<"total 93 octane gas dispatched: "<<totalgasB<<endl;
 cout<<"total 97 octane gas dispatched: "<<totalgasC<<endl;
}

int main(){
 srand(time(NULL));
 Customer *cus;
 for(int i=0;i<10;i++){
  cus=new Customer;
  cus->request();
  delete cus; 
 }
 Customer::total();
}