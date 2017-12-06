#include "DateStuff.h"
#include <iostream>
using namespace std;

const char* DayText[] = 
{
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

using namespace DateStuff;

int main()
{
	int year = 1997;
	int month = 4;
	int day = 1;

	cout.setf(ios::boolalpha);
	cout << "Date: " << month << "/" << day << "/" << year << endl;
	cout << "Leap year? " << IsLeap(year) << endl;
	cout << "Day of week: " << DayText[DayOfWeek(year, month, day)] << endl;
	cout << "Day of year: " << DayOfYear(year, month, day) << endl;
	cout << "Days in month: " << EndOfMonth(year, month) << endl;
	cout << "Days in previous month: " << DaysInPrevMonth(year, month) << endl;
	cout << "Days in next month: " << DaysInNextMonth(year, month) << endl;
	cout << "3rd Saturday of month: " << NthWeekDay(3, SATURDAY, year, month) << endl;
	long jday = GregToJul(year, month, day);
	cout << "Julian day number: " << jday << endl;
	int year2, month2, day2;
	JulToGreg(jday + 100, year2, month2, day2);
	cout << "100 days from now: " << month2 << "/" << day2 << "/" << year2 << endl;
}