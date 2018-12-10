#include <iostream>
#include <iomanip>

using namespace std;

class Date{
	private:
		long yyyymmdd;

	public:
		Date(int = 7, int = 4, int = 2012);
		Date(long);
		void setDate(int, int, int);
		void showDate();
		
};


Date :: Date(long date){
	yyyymmdd = date;
}

Date :: Date(int mm, int dd, int yyyy){
	yyyymmdd = (long)(yyyy) << 18 | (long)(mm) << 9 | (long)(dd);
}

void Date :: setDate(int mm, int dd, int yyyy){
	yyyymmdd = (long)(yyyy) << 18 | (long)(mm) << 9 | (long)(dd);
	return;
}

void Date :: showDate(){
	cout << "The date is ";
	int year = yyyymmdd >> 18;
	int month = (yyyymmdd >> 9) & ((1ll << 9) - 1);
	int day = yyyymmdd & ((1ll << 9) - 1);

	cout << setfill('0')
		 << setw(2) << month << '/'
		 << setw(2) << day << '/'
		 << setw(2) << year % 100 << endl;
	return;
}

int main(){
	Date a, b, c(8, 26, 2016);

	b.setDate(12, 25, 2009);
	a.showDate();
	b.showDate();
	c.showDate();
}
