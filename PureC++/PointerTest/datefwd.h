// 日期类和函数的声明
#ifndef DATEFWD_H
#define DATEFWD_H

#include <limits.h>
#include <string>

namespace DateStuff
{
	// 常数和数据
	enum YearLimits {MIN_YEAR = 1583, MAX_YEAR = INT_MAX};
	enum Days {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, 
				FRIDAY, SATURDAY, SUNDAY, DAY_ERROR};
	enum Months {MONTH_ERROR, JANUARY, FEBURARY, MARCH, APRIL, MAY, JUNE, 
				JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

	// 类
	struct Duration;
	class Year;
	class YMonth;
	class Date;
	class FullData;
	class Date_Exception;

	// 常用的日期函数
	// 系统日期
	void Today(int&, int&, int&);

	// 闰年测试
	bool IsLeap(int y);

	// 其他的有效性检查
	bool IsValidYear(int y);
	bool IsValidMonth(int m);
	bool IsValidMonth(int y, int m);
	bool IsValidDay(int m, int d);
	bool IsValidYMDay(int y, int m, int d);

	// 不同的计算方法
	int Compare(int y1, int m1, int d1, int y2, int m2, int d2);
	int DayOfWeek(int y, int m, int d);
	int DayOfYear(int y, int m, int d);
	int EndOfMonth(int y, int m);
	int EndOfYear(int y);
	void NthDay(int n, int y, int& m, int& d);
	int NthWeekDay(int n, int wd, int y, int m);
	int DaysInPrevMonth(int y, int m);
	int DaysInNextMonth(int y, int m);
	int GetDaysInMonth(bool isLeap, int m);
	int GetDaysToDate(bool isLeap, int m);

	int FirstSat(int dow);
	int FirstSatOfMonth(int y, int m);
	int FirstSatOfYear(int y);

	int AbsoluteWeek(int day);
	int AbsoluteWeekOfMonth(int y, int m, int d);
	int AbsoluteWeekOfYear(int y, int m, int d);
	int CommonWeek(int s, int doyom);
	int CommonWeekOfMonth(int y, int m, int d);
	int CommonWeekOfYear(int y, int m, int d);
	void NthCommonWeek(int n, int y, int& day1, int& day2);
	int NumCommonWeeks(int y);

	void AddYears(int yrs, int& y, int& m, int& d);
	void SubtractYears(int yrs, int& y, int& m, int& d);
	void AddMonths(int mths, int& y, int& m, int& d);
	void SubtractMonths(int mths, int& y, int& m, int& d);
	long MonthsBetween(int y1, int m1, int y2, int m2);
	void AddDays(int days, int& y, int& m, int& d);
	void SubtractDays(int days, int& y, int& m, int& d);
	long DaysBetween(int y1, int m1, int d1, int y2, int m2, int d2);
	void AddWeekDays(int wdays, int& y, int& m, int& d);
	void SubtractWeekDays(int wdays, int& y, int& m, int& d);
	long WeekDaysBetween(int y1, int m1, int d1, int y2, int m2, int d2);
	void AddWeeks(int wks, int& y, int& m, int& d);
	void SubtractWeeks(int wks, int& y, int& m, int& d);
	long WeeksBetween(int y1, int m1, int d1, int y2, int m2, int d2);
	Duration Age(int y, int m, int d);
	Duration AgeBetween(int y1, int m1, int d1, int y2, int m2, int d2);

	// Julian日期变换:
	long GregToJul(int y, int m, int d);
	void JulToGreg(long jd, int& y, int& m, int& d);
	int DayOfWeek(long jd);
	int DayOfYear(long jd);

	// 其他的变换
	using std::string;
	string ToString(int y, int m, int d);
	void FromString(const string& str, int& y, int& m, int& d);

	// 其他
	void ResolveMonths(long mths, int& y, int& m);
	void CheckY(int y);
	void CheckYM(int y, int m);
	void CheckYMD(int y, int m, int d);
}

#endif