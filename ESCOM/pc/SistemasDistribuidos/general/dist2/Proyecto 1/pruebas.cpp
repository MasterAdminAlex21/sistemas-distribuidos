#include <bits/stdc++.h>

using namespace std;

// class declaration section
class julianDate;

class Date{
  private:
    int month, day, year;
  public:
    Date(int = 7, int = 4, int = 2012);  // constructor
    // constructor for converting from long to Date
    Date(long);
    void showDate();
    operator julianDate();
};

class julianDate{
  private:
   long jdate;
  public:
    julianDate(long = 0);
    operator Date();
    void showjulianDate();
};

// class implementation section
Date::Date(int mm, int dd, int yyyy){  // constructor
  month = mm;
  day = dd;
  year = yyyy;
}

// constructor for converting from long to Date
julianDate::julianDate(long z){
  jdate = z;
}

// member function to display a date
void Date::showDate(){
  cout << setfill('0') << setw(2) << month << '/' << setw(2) << day << '/' << setw(2) << year % 100;
    return;
}

Date::operator julianDate(){
  int mp, yp, T;
  long Julian;
  if(month <= 2){
    mp = 0; 
    yp = year - 1;
  }else{
    mp = int(0.4 * month + 2.3);
    yp = year;
  }
  T = int(yp / 4) - int(yp / 100) + int(yp / 400);
  Julian = 365 * year + 31 * (month - 1) + day + T - mp;

  //cout << Julian << endl;
  return (julianDate(Julian));
}

void julianDate::showjulianDate(){
  cout << jdate << endl;
  return;
}

int main(){

  int x, y, z;

  cout << "Input  month, day and year separated by a space: ";
  cin >> x >> y >> z;
  Date a(x, y, z);
  
  cout << "Your date is: ";
  a.showDate();

  julianDate lol;

  lol = julianDate(a);
  
  cout << "\nThe Julian date is: " ;
  lol.showjulianDate();

  return 0;
}