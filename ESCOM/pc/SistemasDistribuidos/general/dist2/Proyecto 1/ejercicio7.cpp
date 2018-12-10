#include <iostream>
#include <iomanip>

using namespace std;

class JulianDate;

class GregorianDate{
	private:
		int month, day, year;
  	public:
    	GregorianDate(int = 7, int = 4, int = 2012);
    	operator JulianDate();
    	void showDate();
};

class JulianDate{
	private:
    	long yyyymmdd;
  	public:
    	JulianDate(long = 0);
    	void showint();
};

GregorianDate :: GregorianDate(int mm, int dd, int yyyy){
  	month = mm;
  	day = dd;
  	year = yyyy;
}

GregorianDate :: operator JulianDate(){
  	long temp;
  	long MP, YP, T;
  	if(month <= 2){
  		MP = 0;
  		YP = year - 1;
  	}else{
  		MP = int(0.4 * month + 2.3);
  		YP = year;
  	}
  	T = int(YP / 4.0) - int(YP / 100.0) + int(YP / 400.0);
  	return JulianDate(365 * year + 31 * (month - 1) + day + T - MP);
}

void GregorianDate :: showDate(){
  	cout << setfill('0')
        << setw(2) << month << '/'
        << setw(2) << day << '/'
        << setw(2) << year % 100;
    cout << endl << endl;
  	return;
}

JulianDate :: JulianDate(long ymd){
  	yyyymmdd = ymd;
}

void JulianDate :: showint(){
  	cout << yyyymmdd << endl << endl;
  	return;
}

int main(){
	GregorianDate a(1, 31, 2011), b(3, 16, 2012);
	JulianDate c, d;
	cout << "Date GregorianDate a: ";
	a.showDate();
	cout << "Date GregorianDate b: ";
	b.showDate();

	//Cast GreorianDate to JulianDate
	c = JulianDate(a);
	d = JulianDate(b);


	cout << "Date JulianDate a: ";
	c.showint();
	cout << "Date JulianDate b: ";
	d.showint();

  	return 0;
}