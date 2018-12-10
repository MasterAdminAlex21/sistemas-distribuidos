#include<iostream>
#include<time.h>
using namespace std;

class Customer{
private:
 int reqgas;
 int time;
 static int totalgas;
public:
 Customer();
 ~Customer();//el libro tiene como destructor el signo -, cuando en realidad se usa el ~
 void request();
 static void total();
};

int Customer::totalgas=0; 

Customer::Customer(){
 cout<<"A customer has arrived!!!"<<endl;
}

Customer::~Customer(){
 cout<<"the customer has left"<<endl;
}

void Customer::request(){ 
 reqgas=(3+rand())%15;
 time=(1+rand())%15;
 cout<<"the customer request "<<reqgas<<" gallons of gas, in "<<time<<" minutes."<<endl;
 totalgas+=reqgas;
}

void Customer::total(){
 cout<<"total gas dispatched: "<<totalgas<<endl;
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