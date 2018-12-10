#include <iostream>
#include <iomanip>

using namespace std;

class Date{
	private:
		int month;
		int day;
		int year;
	public:
		Date(int = 7, int = 4, int = 2012);
		void showDate();
		void swap(Date &);		
};

Date::Date(int mm, int dd, int yyyy){
	month = mm;
	day = dd;
	year = yyyy;
}

void Date::showDate(){
	cout << "The date is ";
	cout << setfill('0') << setw(2) << month << '/' << setw(2) << day << '/' << setw(2) << year % 100; 
	cout << endl;
}

void Date::swap(Date &temp){
	int tempstore;
	tempstore = temp.day;
	temp.day = day;
	day = tempstore;

	tempstore = temp.month;
	temp.month = month;
	month = tempstore;

	tempstore =  temp.year;
	temp.year = year;
	year = tempstore;
	return;
}

int main(){
	Date oldDate(4,3,1999);
	Date newDate(12,18,2012);

	cout << "The date stored in oldDate is ";
	oldDate.showDate();

	cout << "\nThe date stored in newDate is ";
	newDate.showDate();

	newDate.swap(oldDate);
	cout << "\n\nAfter the swap:\n\n";
	cout << "The date stored in oldDate is ";
	oldDate.showDate();
	
	cout << "\nThe date stored in newDate is ";
	newDate.showDate();
	cout << '\n';
	return 0;
}
