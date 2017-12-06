#include "DateStuff.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using std::min;


namespace DateStuff
{
	static const int DaysInMonth[][13] = 
	{
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

	static const int DaysToDate[][13] = 
	{
		{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
		{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366},
	};

	int DateStuff::GetDaysInMonth(bool isLeap, int m)
	{
		assert(isLeap == 0 || isLeap == 1);
		if (!IsValidMonth(m))
		{
			throw Date_Exception(MONTH_ERROR);
		}
		return DaysInMonth[isLeap][m];
	}

	int DateStuff::GetDaysToDate(bool isLeap, int m)
	{
		assert(isLeap == 0 || isLeap == 1);
		// m必须在[1, 13]之间
		if (m < 1 || m > 13)
		{
			throw Date_Exception(MONTH_ERROR);
		}
		return DaysToDate[isLeap][m - 1];
	}

	long DateStuff::GregToJul(int year, int month, int day)
	{
		// 转换阳历日期(Gregorian)为完整的Julian成员
		CheckYMD(year, month, day);
		long m = (long)month;
		long d = (long)day;
		long y = (long)year;
		return d - 32075L 
				+ 1461L * (y + 4800 + (m - 14L) / 12L) / 4L 
				+ 367L * (m - 2L - (m - 14L) / 12L * 12L) / 12L
				- 3L * ((y + 4900L + (m - 14L) / 12L) / 100L) / 4L;
	}

	void DateStuff::JulToGreg(long jday, int& year, int& month, int& day)
	{
		// 转换Julian天数为阳历日期(Gregorian)
		long t1 = jday + 68569L;
		long t2 = 4L * t1 / 146097L;
		t1 -= (146097L * t2 + 3L) / 4L;

		long y = 4000L * (t1 + 1) / 1461001L;
		t1 = t1 - 1461L * y / 4L + 31;

		long m = 80L * t1 / 2447L;
		day = int(t1 - 2447L * m / 80L);

		t1 = m / 11L;
		month = int(m + 2L - 12L * t1);

		year = int(100L * (t2 - 49L) + y + t1);
	}

	void DateStuff::NthDay(int n, int year, int& month, int& day)
	{
		CheckY(year);
		if (n < 1 || n > 366)
		{
			throw Date_Exception(Date_Exception::DAY_ERROR);
		}

		int row = IsLeap(year);
		if (n > DaysToDate[row][12])
		{
			throw Date_Exception(Date_Exception::RANGE_ERROR);
		}

		for (month = 0; month < 13; ++month)
		{
			if (DaysToDate[row][month] >= n)
			{
				break;
			}
		}

		if (DaysToDate[row][month] > n)
		{
			day = int(n - DaysToDate[row][month - 1]);
		}
		else
		{
			day = int(DaysToDate[row][month] - DaysToDate[row][month]);
		}
	}

	int DateStuff::NthWeekDay(int n, int weekDay, int year, int month)
	{
		CheckYM(year, month);
		if (!(1 <= n && n <= 5) || !(MONDAY <= weekDay && weekDay <= SUNDAY))
		{
			throw Date_Exception(DAY_ERROR);
		}

		// 查找所需的星期中一天第一次出现的地方
		long jday = GregToJul(year, month, 1);
		while(int(jday % 7L) != weekDay)
		{
			++jday;
		}

		// 被所需的星期中的一天第n个出现的超前星期数
		for (int weekno = 1; weekno < n; ++weekno)
		{
			jday += 7L;
		}

		// 转换Julian为阳历并将该天返回
		int day;
		int tempmonth = month;
		JulToGreg(jday, year, month, day);
		if (month != tempmonth)
		{
			throw Date_Exception(Date_Exception::RANGE_ERROR);
		}
		return day;
	}

	int DateStuff::DaysInPrevMonth(int year, int month)
	{
		CheckYM(year, month);
		if (month == 1)
		{
			--year;
			month = 12;
		}
		else
		{
			--month;
		}
		return DaysInMonth[IsLeap(year)][month];
	}

	int DateStuff::DaysInNextMonth(int year, int month)
	{
		CheckYM(year, month);
		if (month == 12)
		{
			++year;
			month = 1;
		}
		else
		{
			++month;
		}
		return DaysInMonth[IsLeap(year)][month];
	}

	string DateStuff::Date_Exception::s_ErrorStrings[Date_Exception::NUM_ERRORS] = 
	{
		"Invalid Date",
		"Invalid Year",
		"Invalid Month",
		"Invalid Day",
		"Range error",
		"Invalid Birthday"
	};

	string DateStuff::Date_Exception::ErrorString(int cod) const
	{
		assert(BEGIN <= cod && cod < END);
		return s_ErrorStrings[cod - BEGIN];
	}

	int DateStuff::FirstSat(int dow)
	{
		// 计算第一个星期六的序数
		// 已知（一个月或一年的）第一天是星期几
		// 注意：假定MONDAY = 0...SUNDAY = 6
		assert(MONDAY <= dow && dow <= SUNDAY);
		if (dow == SUNDAY)
		{
			return 7;
		}
		else if (dow == SATURDAY)
		{
			return 1;
		}
		else
			return SATURDAY - dow + 1;
	}

	int DateStuff::CommonWeek(int s, int d)
	{
		// s是每月或每年的第一个星期六的序数
		// d是每月或每年的相应天的序数
		assert(1 <= s && s <= 7);
		assert(1 <= d && d <= 366);
		if (d <= s)
		{
			return 1;
		}
		else
		{
			return 2 + (d - s - 1) / 7;
		}
	}

	void DateStuff::Today(int& y, int& m, int& d)
	{
		time_t tval = time(0);
		struct tm* tmp = localtime(&tval);
		
		d = tmp->tm_mday;
		m = tmp->tm_mon + 1;
		y = tmp->tm_year + 1900;
	}

	void DateStuff::NthCommonWeek(int n, int y, int& day1, int& day2)
	{
		if (!(1 <= day1 && day1 <= EndOfYear(y) ) || !(1 <= day2 && day2 <= EndOfYear(y)))
		{
			throw Date_Exception(DAY_ERROR);
		}

		int s = FirstSatOfYear(y);
		if (n <= 1)
		{
			day1 = 1;
			day2 = s;
		}
		else
		{
			int nc = NumCommonWeeks(y);
			if (n > nc)
			{
				n = nc;
			}
			day1 = s + 1 + 7 * (n - 2);
			day2 = (n == nc) ? EndOfYear(y) : s + 7 * (n - 1);
		}
	}

	void DateStuff::AddYears(int yrs, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		if (y > MAX_YEAR - yrs)
		{
			throw Date_Exception(Date_Exception::RANGE_ERROR);
		}
		y += yrs;
		d = min(d, EndOfMonth(y, m));
	}

	void DateStuff::SubtractYears(int yrs, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		if (y < MIN_YEAR + yrs)
		{
			throw Date_Exception(Date_Exception::RANGE_ERROR);
		}
		y -= yrs;
		d = min(d, EndOfMonth(y, m));
	}

	void DateStuff::AddMonths(int mths, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		ResolveMonths(y * 12 + m + mths, y, m);
		d = min(d, EndOfMonth(y, m));
	}

	void DateStuff::SubtractMonths(int mths, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		ResolveMonths(y * 12 + m - mths, y, m);
		d = min(d, EndOfMonth(y, m));
	}

	void DateStuff::AddWeekDays(int wdays, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		// 注意：这种算法使用在MONDAY == 0的情况
		// 备份到最近的周日
		int dayno = DayOfWeek(y, m, d);
		if (dayno > FRIDAY)
		{
			SubtractDays(dayno - FRIDAY, y, m, d);
			dayno = FRIDAY;
		}

		// 首先被星期提前
		if (wdays >= 5)
		{
			AddWeeks(wdays / 5, y, m, d);
		}

		// 现在提前其余的天
		int extra = int(wdays % 5);
		if (dayno + extra > FRIDAY)
		{
			extra == 2;	// 跳过周末
		}
		if (extra > 0)
		{
			AddDays(extra, y, m, d);
		}
	}

	void DateStuff::SubtractWeekDays(int wdays, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		// 注意：这算法使用到MONDAY == 0的情况
		// 提前到最近的工作日
		int dayno = DayOfWeek(y, m, d);
		if (dayno > FRIDAY)
		{
			AddDays(7 - dayno, y, m, d);
			dayno = MONDAY;
		}

		// 首先减去星期
		SubtractWeeks(wdays / 5, y, m, d);

		// 现在备份其余的天
		int extra = int(wdays % 5);
		if (dayno - extra < MONDAY)
		{
			extra += 2;
		}
		// 跳过周末
		SubtractDays(extra, y, m, d);
	}

	long DateStuff::WeekDaysBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		CheckYMD(y1, m1, d1);
		CheckYMD(y2, m2, d2);

		// 备份到最近的工作日
		int dayno1 = DayOfWeek(y1, m1, d1);
		if (dayno1 > FRIDAY)
		{
			SubtractDays(dayno1 - FRIDAY, y1, m1, d1);
			dayno1 = FRIDAY;
		}
		int dayno2 = DayOfWeek(y2, m2, d2);
		if (dayno2 > FRIDAY)
		{
			SubtractDays(dayno2 - FRIDAY, y2, m2, d2);
			dayno2 = FRIDAY;
		}

		long weeks = WeeksBetween(y1, m1, d1, y2, m2, d2);
		int extra = int(dayno2 - dayno1);
		long days = weeks * 5 + extra;
		return days;
	}

	DateStuff::Duration DateStuff::Age(int y, int m, int d)
	{
		int y2, m2, d2;
		Today(y2, m2, d2);
		return AgeBetween(y, m, d, y2, m2, d2);
	}

	DateStuff::Duration DateStuff::AgeBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		// 查找两个日期的顺序
		int order = Compare(y1, m1, d1, y2, m2, d2);
		if (order == 0)
		{
			return Duration(0, 0, 0);
		}
		else if (order > 0)
		{
			// 使date1先于date2
			using std::swap;
			swap(y1, y2);
			swap(m1, m2);
			swap(d1, d2);
		}

		int years = y2 - y1;
		int months = m2 - m1;
		int days = d2 - d1;
		assert(years > 0 || 
			years == 0 && months > 0 || 
			years == 0 && months == 0 && days > 0);

		int lastMonth = m2;
		int lastYear = y2;
		while(days < 0)
		{
			// 从月借
			assert(months > 0);
			days += DaysInPrevMonth(lastYear, lastMonth--);
			--months;

			// 这时循环是为了防止从2月借1，那样就无法获得足够的天数来使days为非负，这个循环迭代绝不超过两次
		}

		if (months < 0)
		{
			// 向年借
			assert(years > 0);
			months += 12;
			--years;
		}

		return Duration(years, months, days);
	}

	void DateStuff::ResolveMonths(long months, int& y, int& m)
	{
		assert(months > 1582 * 12);

		if (months < 0)
		{
			months = -months;
		}
		y = int(months / 12);
		m = int(months % 12);
		if (m == 0)
		{
			m = 12;
		}
		if (!IsValidYMonth(y, m))
		{
			throw Date_Exception(Date_Exception::RANGE_ERROR);
		}
	}

	void DateStuff::FromString(const string& s, int& y, int& m, int& d)
	{
		y = atoi(s.substr(0, 4).c_str());
		m = atoi(s.substr(4, 2).c_str());
		d = atoi(s.substr(6, 2).c_str());
		if (!IsValidYMDay(y, m, d))
		{
			throw Date_Exception(Date_Exception::DATE_ERROR);
		}
	}

	void DateStuff::CheckYMD(int y, int m, int d)
	{
		if (!IsValidYMDay(y, m, d))
		{
			throw Date_Exception(Date_Exception::DATE_ERROR);
		}
	}

	void DateStuff::CheckYM(int y, int m)
	{
		if (!IsValidYMonth(y, m))
		{
			throw Date_Exception(Date_Exception::DATE_ERROR);
		}
	}

	void DateStuff::CheckY(int y)
	{
		if (!IsValidYear(y))
		{
			throw Date_Exception(Date_Exception::DATE_ERROR);
		}
	}

	string ToString(int y, int m, int d)
	{
		char buf[9];
		sprintf(buf, "%04d%02d%02d", y, m, d);
		return string(buf);
	}

}