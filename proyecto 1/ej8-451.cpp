#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date
{
  private:
    int month;
    int day;
    int year;
  public:
    Date(int = 7, int = 4, int = 2012); // constructor
    void setDate(int, int, int);   // member method to copy a date
    void showDate();               // member method to display a date
    void dayOfWeek();      //here is the new method 
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}
void Date::setDate(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
  return;
}
void Date::showDate()
{
    cout << "The date is ";
    cout << setfill('0')
         << setw(2) << month << "/"
         << setw(2) << day << "/"
         << setw(2) << year % 100; // extract the last 2 year digits
    cout << endl;
  return;
}
void Date::dayOfWeek()
{
 if(month<3){
  month+=12;
  year-=1;
 }
 int century=year/100;
 int yearAux=year/100;
 int t=day+int(26*((month+1)/10)) + yearAux+ int(year/4)+int(century/4)-2*century;
 int dayOW=t%7;
 if(dayOW<0)
  dayOW+=7;
 switch(dayOW){
  case 0:
  cout<<"the day of the week: Saturday"<<endl;
  break;
  case 1:
  cout<<"the day of the week: Sunday"<<endl;
  break;
  case 2:
  cout<<"the day of the week: Monday"<<endl;
  break;
  case 3:
  cout<<"the day of the week: Tuesday"<<endl;
  break;
  case 4:
  cout<<"the day of the week: Wednesday"<<endl;
  break;
  case 5:
  cout<<"the day of the week: Thursday"<<endl;
  break;
  case 6:
  cout<<"the day of the week: Friday"<<endl;
  break;
 }
}
int main()
{
  Date a, b, c(4,1,2000);  // declare 3 objects
  b.setDate(12,25,2009);  // assign values to b"s data members
  a.showDate();           // display object a"s values
  b.showDate();           // display object b"s values
  c.showDate();           // display object c"s values
  a.dayOfWeek();
  b.dayOfWeek();
  c.dayOfWeek();
  return 0;
}
