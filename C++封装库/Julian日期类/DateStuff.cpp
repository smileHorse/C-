#include "DateStuff.h"
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using std::min;

#include "except.h"


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
			Throw(Date, MONTH_ERROR);
		}
		return DaysInMonth[isLeap][m];
	}

	int DateStuff::GetDaysToDate(bool isLeap, int m)
	{
		assert(isLeap == 0 || isLeap == 1);
		// m������[1, 13]֮��
		if (m < 1 || m > 13)
		{
			Throw(Date, MONTH_ERROR);
		}
		return DaysToDate[isLeap][m - 1];
	}

	long DateStuff::GregToJul(int year, int month, int day)
	{
		// ת����������(Gregorian)Ϊ������Julian��Ա
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
		// ת��Julian����Ϊ��������(Gregorian)
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
			Throw(Date, DAY_ERROR);
		}

		int row = IsLeap(year);
		if (n > DaysToDate[row][12])
		{
			Throw(Date, RANGE_ERROR);
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
			Throw(Date, DAY_ERROR);
		}

		// ���������������һ���һ�γ��ֵĵط�
		long jday = GregToJul(year, month, 1);
		while(int(jday % 7L) != weekDay)
		{
			++jday;
		}

		// ������������е�һ���n�����ֵĳ�ǰ������
		for (int weekno = 1; weekno < n; ++weekno)
		{
			jday += 7L;
		}

		// ת��JulianΪ�����������췵��
		int day;
		int tempmonth = month;
		JulToGreg(jday, year, month, day);
		if (month != tempmonth)
		{
			Throw(Date, RANGE_ERROR);
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
		// �����һ��������������
		// ��֪��һ���»�һ��ģ���һ�������ڼ�
		// ע�⣺�ٶ�MONDAY = 0...SUNDAY = 6
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
		// s��ÿ�»�ÿ��ĵ�һ��������������
		// d��ÿ�»�ÿ�����Ӧ�������
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
			Throw(Date, DAY_ERROR);
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
			Throw(Date, RANGE_ERROR);
		}
		y += yrs;
		d = min(d, EndOfMonth(y, m));
	}

	void DateStuff::SubtractYears(int yrs, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		if (y < MIN_YEAR + yrs)
		{
			Throw(Date, RANGE_ERROR);
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
		// ע�⣺�����㷨ʹ����MONDAY == 0�����
		// ���ݵ����������
		int dayno = DayOfWeek(y, m, d);
		if (dayno > FRIDAY)
		{
			SubtractDays(dayno - FRIDAY, y, m, d);
			dayno = FRIDAY;
		}

		// ���ȱ�������ǰ
		if (wdays >= 5)
		{
			AddWeeks(wdays / 5, y, m, d);
		}

		// ������ǰ�������
		int extra = int(wdays % 5);
		if (dayno + extra > FRIDAY)
		{
			extra = 2;	// ������ĩ
		}
		if (extra > 0)
		{
			AddDays(extra, y, m, d);
		}
	}

	void DateStuff::SubtractWeekDays(int wdays, int& y, int& m, int& d)
	{
		CheckYMD(y, m, d);
		// ע�⣺���㷨ʹ�õ�MONDAY == 0�����
		// ��ǰ������Ĺ�����
		int dayno = DayOfWeek(y, m, d);
		if (dayno > FRIDAY)
		{
			AddDays(7 - dayno, y, m, d);
			dayno = MONDAY;
		}

		// ���ȼ�ȥ����
		SubtractWeeks(wdays / 5, y, m, d);

		// ���ڱ����������
		int extra = int(wdays % 5);
		if (dayno - extra < MONDAY)
		{
			extra += 2;
		}
		// ������ĩ
		SubtractDays(extra, y, m, d);
	}

	long DateStuff::WeekDaysBetween(int y1, int m1, int d1, int y2, int m2, int d2)
	{
		CheckYMD(y1, m1, d1);
		CheckYMD(y2, m2, d2);

		// ���ݵ�����Ĺ�����
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
		// �����������ڵ�˳��
		int order = Compare(y1, m1, d1, y2, m2, d2);
		if (order == 0)
		{
			return Duration(0, 0, 0);
		}
		else if (order > 0)
		{
			// ʹdate1����date2
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
			// ���½�
			assert(months > 0);
			days += DaysInPrevMonth(lastYear, lastMonth--);
			--months;

			// ��ʱѭ����Ϊ�˷�ֹ��2�½�1���������޷�����㹻��������ʹdaysΪ�Ǹ������ѭ������������������
		}

		if (months < 0)
		{
			// �����
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
			Throw(Date, RANGE_ERROR);
		}
	}

	void DateStuff::FromString(const string& s, int& y, int& m, int& d)
	{
		y = atoi(s.substr(0, 4).c_str());
		m = atoi(s.substr(4, 2).c_str());
		d = atoi(s.substr(6, 2).c_str());
		if (!IsValidYMDay(y, m, d))
		{
			Throw(Date, DATE_ERROR);
		}
	}

	void DateStuff::CheckYMD(int y, int m, int d)
	{
		if (!IsValidYMDay(y, m, d))
		{
			Throw(Date, DATE_ERROR);
		}
	}

	void DateStuff::CheckYM(int y, int m)
	{
		if (!IsValidYMonth(y, m))
		{
			Throw(Date, DATE_ERROR);
		}
	}

	void DateStuff::CheckY(int y)
	{
		if (!IsValidYear(y))
		{
			Throw(Date, DATE_ERROR);
		}
	}

	string ToString(int y, int m, int d)
	{
		char buf[9];
		sprintf(buf, "%04d%02d%02d", y, m, d);
		return string(buf);
	}

}