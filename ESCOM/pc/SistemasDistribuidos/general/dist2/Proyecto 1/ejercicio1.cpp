#include <iostream>
#include <iomanip>

using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;
		string namesDays[7] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};

	public:
		Date(int = 7, int = 4, int = 2012);
		void setDate(int, int, int);
		void showDate();
		string dayOfWeek(){
			if(month < 3){
				month += 12;
				year--;
			}
			int century = year / 100;
			int yy = year % 100;
			int T = day + (26 * (month + 1)) / 10 + yy + yy / 4 + century / 4 - 2 * century;
			while(T < 0)
				T += 7;
			return namesDays[T % 7];
		}
};

Date :: Date(int mm, int dd, int yyyy){
	month = mm;
	day = dd;
	year = yyyy;
}

void Date :: setDate(int mm, int dd, int yyyy){
	month = mm;
	day = dd;
	year = yyyy;
	return;
}

void Date :: showDate(){
	cout << "The date is ";
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
	cout << a.dayOfWeek() << endl;
	b.showDate();
	cout << b.dayOfWeek() << endl;
	c.showDate();
	cout << c.dayOfWeek() << endl;
}
