#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date
{
  private:
    long yyyymmdd;
  public:
    Date(int = 7, int = 4, int = 2012);   // constructor
    Date(long);           // another constructor
    void showDate();      // member method to display a date
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  yyyymmdd = (yyyy * 10000) + (mm * 100) + dd;
}
Date::Date(long yyyymmdd):yyyymmdd(yyyymmdd)
{
}
void Date::showDate()
{
  cout <<"The date is ";
  cout << setfill('0')
       << setw(2) << (yyyymmdd%10000)/100 << '/'
       << setw(2) << (yyyymmdd%10000)%100 << '/'
       << setw(2) << (yyyymmdd/10000)%100; // extract the last 2 year digits
  cout << endl;
  return;
}
int main()
{
  Date a, b(4,1,1998), c(20090515L); // declare three objects
  a.showDate();           // display object a's values
  b.showDate();           // display object b's values
  c.showDate();           // display object c's values
  return 0;
}
