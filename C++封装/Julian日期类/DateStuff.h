// Date功能模块
#ifndef DATESTUFF_H
#define DATESTUFF_H

#include <assert.h>
#include "datefwd.h"
#include <exception>
using std::string;

namespace DateStuff
{
	// 类
	struct Duration
	{
		int m_Year;
		int m_Month;
		int m_Day;
		Duration(int y = 0, int m = 0, int d = 0)
		{
			m_Year = y;
			m_Month = m; 
			m_Day = d;
		}
	};

	// 异常类
	using std::exception;
	class Date_Exception : exception
	{
	public:
		Date_Exception(int cod, const string& msg = "")
			: exception((s_ErrorStrings[cod] + ":" + msg).c_str())
		{
			assert(BEGIN <= cod && cod < END);
		}
		enum {BEGIN = 200};
		enum {DATE_ERROR = BEGIN, YEAR_ERROR, MONTH_ERROR, 
				DAY_ERROR, RANGE_ERROR, BIRTHDAY_ERROR,	
				END, NUM_ERRORS = END - BEGIN};

	protected:
		string ErrorString(int) const;	// 重载
	
	private:
		static string s_ErrorStrings[NUM_ERRORS];
	};

	// 内联
	inline bool IsLeap(int y)
	{
		// 确定是否是闰年（返回1或0）
		return !!(y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	}

	inline bool IsValidYear(int y)
	{
		return MIN_YEAR <= y && y <= MAX_YEAR;
	}

	inline bool IsValidMonth(int m)
	{
		return 1 <= m && m <= 12;
	}

	inline bool IsValidYMonth(int y, int m)
	{
		return IsValidYear(y) && IsValidMonth(m);
	}

	inline bool IsValidDay(int m, int d)
	{
		return IsValidMonth(m) && 
			1 <= d && d <= GetDaysInMonth(true, m);
	}

	inline bool IsValidYMDay(int y, int m, int d)
	{
		return IsValidYMonth(y, m) && 
			1 <= d && d <= EndOfMonth(y, m);
	}

	inline int DayOfWeek(long jd)
	{
		return int(jd % 7L);
	}

	inline int DayOfWeek(int y, int m, int d)
	{
		CheckYMD(y, m, d);
		return int(GregToJul(y, m, d) % 7);
	}

	inline int DayOfYear(long jd)
	{
		int y, m, d;
		JulToGreg(jd, y, m, d);
		return DayOfYear(y, m, d);
	}

	inline int DayOfYear(int y, int m, int d)
	{
		CheckYMD(y, m, d);
		return int(GetDaysToDate(IsLeap(y), m) + d);
	}

	inline int EndOfMonth(int y, int m)
	{
		CheckYM(y, m);
		return GetDaysInMonth(IsLeap(y), m);
	}

	inline int EndOfYear(int y)
	{
		CheckY(y);
		return GetDaysToDate(IsLeap(y), 13);
	}

	inline int AbsoluteWeek(int day)
	{
		assert(1 <= day && day <= 366);
		return (day - 1) / 7 + 1;
	}

	inline int AbsoluteWeekOfYear(int y, int m, int d)
	{
		CheckYMD(y, m, d);
		return AbsoluteWeek(DayOfYear(y, m, d));
	}

	inline int AbsoluteWeekOfMonth(int y, int m, int d)
	{
		CheckYMD(y, m, d);
		return AbsoluteWeek(d);
	}

	inline int CommonWeekOfMonth(int y, int m, int d)
	{
		CheckYMD(y, m, d);
		return CommonWeek(FirstSatOfMonth(y, m), d);
	}

	inline int CommonWeekOfYear(int y, int m, int d)
	{
		CheckYMD(y, m, d);
		return CommonWeek(FirstSatOfYear(y), DayOfYear(y, m, d));
	}

	inline int FirstSatOfYear(int y)
	{
		CheckY(y);
		return FirstSat(DayOfWeek(y, 1, 1));
	}

	inline int FirstSatOfMonth(int y, int m)
	{
		CheckYM(y, m);
		return FirstSat(DayOfWeek(y, m, 1));
	}

	inline int Compare(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		// 返回两日期中间天数（有符号数）
		return GregToJul(y1, m1, d1) - GregToJul(y2, m2, d2);
	}

	inline long DaysBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		// 用于比较的同义词
		return Compare(y1, m1, d1, y2, m2, d2);
	}

	inline int NumCommonWeeks(int y)
	{
		CheckY(y);
		return (EndOfYear(y) - FirstSatOfYear(y) - 1) / 7 + 2;
	}
	
	inline long MonthsBetween(int y1, int m1, int y2, int m2)
	{
		CheckYM(y1, m1);
		CheckYM(y2, m2);
		return (y1 - y2) * 12L + m1 - m2;
	}

	inline void AddDays(int days, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		JulToGreg(GregToJul(y, m, d) + days, y, m, d);
	}

	inline void SubtractDays(int days, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		JulToGreg(GregToJul(y, m, d) - days, y, m, d);
	}

	inline void AddWeeks(int wks, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		AddDays(wks * 7, y, m, d);
	}

	inline void SubtractWeeks(int wks, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		SubtractDays(wks * 7, y, m, d);
	}

	inline long WeeksBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		CheckYMD(y1, m1, d1);
		CheckYMD(y2, m2, d2);
		return DaysBetween(y1, m1, d1, y2, m2, d2) / 7L;
	}
}
#endif