#include <iostream>
#include <iomanip>
using namespace std;
// class declaration section
class Date
{
  private:
    int month, day, year;
  public:
    Date(int = 7, int = 4, int = 2012);  // constructor
    // constructor for converting from long to Date
    Date(long);
    operator long();
    void showDate();
};
// class implementation section
Date::Date(int mm, int dd, int yyyy)  // constructor
{
  month = mm;
  day = dd;
  year = yyyy;
}
// constructor for converting from long to Date
Date::Date(long findate)
{
  year = int(findate/10000.0);
  month = int((findate - year * 10000.0)/100.0);
  day = int(findate - year * 10000.0 - month * 100.0);
}
// member function to display a date
void Date::showDate()
{
  cout << setfill('0')
       << setw(2) << month << "/"
       << setw(2) << day << "/"
       << setw(2) << year % 100;
  return;
}

//convert
Date::operator long(){
 int mp,yp;
 if(month<=2){
  mp=0;
  yp=year-1;
 }else{
  mp=(0.4*month+2.3);
  yp=year;
 }
 int t=(yp/4)-(yp/100)+(yp/400);
 int Julian=365*year + 31*(month-1) + day+t-mp;
 return Julian;

}

int main()
{
  Date g1(1,31,2011),g2(3,16,2012);
  long j1,j2;
  j1=long(g1);
  cout<<"Gregorian date 1: ";
  g1.showDate();
  cout<<"\nThe julian date of the gregorian date: "<<j1<<endl;

  j2=long(g2);
  cout<<"Gregorian date 2: ";
  g2.showDate();
  cout<<"\nThe julian date of the gregorian date: "<<j2<<endl;
  return 0;
}
