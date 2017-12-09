// 测试Date和FullDate
#include <iostream>
#include <stdexcept>
#include "fulldate.h"

using namespace DateStuff;
using namespace std;

void checkDate(int, int, int);
const char* DayText[] = 
{
	"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

int main()
{
	// 测试无效的日期
	checkDate(0, 3, 14);
	checkDate(1997, 0, 12);
	checkDate(1998, 13, 1);
	checkDate(97, 1, 12);
	checkDate(1999, 2, 29);
	checkDate(1900, 2, 29);
	Date empty(0, 0, 0);
	cout << "empty: \"" << empty.ToString() << "\"\n";
	try
	{
		Date empty2("");
		cout << "empty2: \"" << empty2.ToString() << "\"\n";
	}
	catch(Date_Exception& ex)
	{
		cout << ex.what() << endl;
	}

	Date d1 = string("20000101");
	Date d2(2000, 3, 1);
	cout << "Day of week for d1: " << d1.ToString() << " == " << DayText[d1.DayOfWeek()] << endl;
	cout << "Day of week for d2: " << d2.ToString() << " == " << DayText[d2.DayOfWeek()] << endl;

	Date p1(1996, 2, 29);
	Date p2("20000229");

	cout << "p1 == " << p1.ToString() << endl;
	cout << "p2 == " << p2.ToString() << endl;

	Duration d = p1.AgeBetween(p2);
	cout << "Duration between p1 and p2: " << d.m_Year << " years, " << d.m_Month << " months, " << d.m_Day << " days\n";

	Duration dd = p1.AgeBetween(d2);
	cout << "Duration between p1 and d2(20000301): " << dd.m_Year << " years, " << dd.m_Month << " months, " << dd.m_Day << " days\n";

	if (p1 < p2)
	{
		p1.AddYears(d.m_Year);
		p1.AddMonths(d.m_Month);
		p1.AddDays(d.m_Day);
	}
	else if (p1 > p2)
	{
		p2.AddYears(d.m_Year);
		p2.AddMonths(d.m_Month);
		p2.AddDays(d.m_Day);
	}

	cout << "p1 == p2 (after adding Duration(p1, p2)): " << (p1 == p2 ? "Yes" : "No") << endl;

	FullDate today;
	Date f(today);
	cout << "Today: " << f.ToString() << endl;
	f.AddWeekDays(2);
	cout << "+2 weekdays: " << f.ToString() << endl;
	f.AddWeekDays(10);
	cout << "+10 weekdays: " << f.ToString() << endl;
	f.AddWeekDays(30);
	cout << "+30 weekdays: " << f.ToString() << endl;
	f.SubtractWeekDays(30);
	cout << "-30 weekdays: " << f.ToString() << endl;
	f.SubtractWeekDays(10);
	cout << "-10 weekdays: " << f.ToString() << endl;
	f.SubtractWeekDays(2);
	cout << "-2 weekdays: " << f.ToString() << endl;

	cout << "WeekdaysBetween 12/11/96 and 12/13/96: " << Date(1996, 12, 11).WeekDaysBetween(Date(1996, 12, 13)) << endl;
	cout << "WeekdaysBetween 12/13/96 and 12/27/96: " << Date(1996, 12, 13).WeekDaysBetween(Date(1996, 12, 27)) << endl;
	cout << "WeekdaysBetween 12/27/96 and 2/7/97: " << Date(1996, 12, 27).WeekDaysBetween(Date(1997, 2, 7)) << endl;

	FullDate f1(d1), f2(d2);
	Duration f12 = f2 - f1;
	cout << "d2 - d1 == " << f12.m_Year << " years, " << f12.m_Month << " months, " << f12.m_Day << " days\n";
}

void checkDate(int year, int month, int day)
{
	try
	{
		Date(year, month, day);
		cout << "Validity check FAILED" << endl;
	}
	catch(Date_Exception& ex)
	{
		cout << "Validity check PASSED (" << ex.what() << ")" << endl;
	}
}