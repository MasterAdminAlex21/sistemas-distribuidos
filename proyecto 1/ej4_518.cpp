#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date
{
  public:
    int month;
    int day;
    int year;
    Date(int = 7, int = 4, int = 2012);   // constructor
    void showDate();      // method to display a date
    void swap(Date&);    // method to swap two dates
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)
{
  month = mm;
  day = dd;
  year = yyyy;
}
void Date::showDate()
{
  cout << setfill('0')
       << setw(2) << month << "/"
       << setw(2) << day << "/"
       << setw(2) << year % 100;
  return;
}
void Date::swap(Date& temp) // method to swap two dates
{
  int tempstore;
  // swap the day member
  tempstore = temp.day;
  temp.day = day;
  day = tempstore;
  // swap the month member
  tempstore = temp.month;
  temp.month = month;
  month = tempstore;
  // swap the year member
  tempstore = temp.year;
  temp.year = year;
  year = tempstore;
  return;
}
int main()
{
  Date oldDate(4,3,1999);
  Date newDate(12,18,2012);
 
  cout << "The date stored in oldDate is ";
  oldDate.showDate();
  cout << "\nThe date stored in newDate is ";
  newDate.showDate();
  newDate.swap(oldDate);  // swap dates by passing an address
  cout << "\n\nAfter the swap:\n" <<endl;
  cout << "The date stored in oldDate is ";
  oldDate.showDate();
  cout << "\nThe date stored in newDate is ";
  newDate.showDate();
  cout << endl;
  return 0;
}
