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
    long getJulianDate();
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
       << setw(2) << month << '/'
       << setw(2) << day << '/'
       << setw(2) << year % 100;
  return;
}

long Date::getJulianDate(){
	long MP, YP, T;
	if( month <= 2 ){
		MP = 0;
		YP = (year-1);
	}
	else{
		MP = int( 0.4 * month + 2.3 );
		YP = year;
	}
	T = int( YP / 4 ) - int( YP/100 ) + int( YP / 400 );
	return (365 * year) + ( 31 * ( month - 1) ) + day + T - MP;
}

int main()
{
  Date a( 1 , 31 , 2011 ), b( 3 , 16 , 2012 );
  cout << a.getJulianDate()<< "\n";
  cout << b.getJulianDate()<< "\n";

  return 0;
}