#include <iostream>
#include <string>

using namespace std;

int main( )
{
int n=2;  
double pr=78.7;

n= n + (++n);
cout << n << endl;

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

cout << "precio " << pr << endl;

return 0;
}
