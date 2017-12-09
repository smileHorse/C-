#ifndef DATE_H
#define DATE_H

#include "DateStuff.h"
#include "year.h"
#include "ymonth.h"

namespace DateStuff
{
	class Date
	{
	public:
		Date(int = 0, int = 0, int = 0);
		Date(const string&);
		Date(const Year&);
		Date(const YMonth&);

		// 附加的赋值(为了提高效率)
		Date& operator=(const string&);
		Date& operator=(const Year&);
		Date& operator=(const YMonth&);

		// 存取器
		int GetYear() const;
		int GetMonth() const;
		int GetDay() const;

		// 测试
		bool IsValidYear() const;
		bool IsValidYMonth() const;
		bool IsValidYMDay() const;
		virtual bool IsValid() const;
		bool IsEmpty() const;

		// 比较
		int Compare(const Date&) const;
		bool operator==(const Date&) const;
		bool operator!=(const Date&) const;
		bool operator<(const Date&) const;
		bool operator>(const Date&) const;
		bool operator<=(const Date&) const;
		bool operator>=(const Date&) const;
		
		// 基本计算
		void AddYears(int years);
		void SubtractYears(int years);
		int YearsBetween(const Date&) const;
		void AddMonths(long months);
		void SubtractMonths(long months);
		long MonthsBetween(const Date&) const;
		void AddDays(long days);
		void SubtractDays(long days);
		long DaysBetween(const Date&) const;
		void AddWeeks(long weeks);
		void SubtractWeeks(long weeks);
		long WeeksBetween(const Date&) const;
		void AddWeekDays(long days);
		void SubtractWeekDays(long days);
		long WeekDaysBetween(const Date&) const;
		Duration operator-(const Date&) const;

		// 特殊请求
		int DayOfWeek() const;
		int DayOfYear() const;
		int EndOfMonth() const;
		int EndOfYear() const;
		Duration AgeBetween(const Date&) const;
		Duration Age() const;
		static Date Today();

		// 变换
		string ToString() const;

	protected:
		int m_Year;
		int m_Month;
		int m_Day;
	};

	inline Date::Date(const Year& y)
	{
		m_Year = y.GetYear();
		m_Month = 0;
		m_Day = 0;
	}

	inline Date::Date(const YMonth& ym)
	{
		m_Year = ym.GetYear();
		m_Month = ym.GetMonth();
		m_Day = 0;
	}

	inline Date& Date::operator =(const Year& y)
	{
		assert(y.IsEmpty() || y.IsValid());
		m_Year = y.GetYear();
		m_Month = 0;
		m_Day = 0;
		return *this;
	}

	inline Date& Date::operator =(const YMonth& ym)
	{
		assert(ym.IsEmpty() || ym.IsEmpty());
		m_Year = ym.GetYear();
		m_Month = ym.GetMonth();
		m_Day = 0;
		return *this;
	}

	inline int Date::GetYear() const
	{
		return m_Year;
	}

	inline int Date::GetMonth() const
	{
		return m_Month;
	}

	inline int Date::GetDay() const
	{
		return m_Day;
	}

	inline bool Date::IsValidYear() const
	{
		return DateStuff::IsValidYear(m_Year);
	}

	inline bool Date::IsValidYMonth() const
	{
		return DateStuff::IsValidYMonth(m_Year, m_Month);
	}

	inline bool Date::IsValidYMDay() const
	{
		return DateStuff::IsValidYMDay(m_Year, m_Month, m_Day);
	}

	inline bool Date::IsValid() const
	{
		return IsEmpty() || 
			(m_Day == 0 && m_Month == 0 && IsValidYear()) || 
			(m_Day == 0 && IsValidYMonth()) || 
			IsValidYMDay();
	}

	inline bool Date::IsEmpty() const
	{
		return m_Day == 0 && m_Month == 0 && m_Year == 0;
	}

	inline int Date::Compare(const Date& r) const
	{
		int ydiff = m_Year - r.m_Year;
		int mdiff = m_Month - r.m_Month;
		return (ydiff == 0) ? ((mdiff == 0) ? m_Day - r.m_Day : mdiff) : ydiff;
	}

	inline bool Date::operator==(const Date& r) const
	{
		return Compare(r) == 0;
	}

	inline bool Date::operator!=(const Date& r) const
	{
		return Compare(r) != 0;
	}

	inline bool Date::operator<(const Date& r) const
	{
		return Compare(r) < 0;
	}

	inline bool Date::operator>(const Date& r) const
	{
		return Compare(r) > 0;
	}

	inline bool Date::operator<=(const Date& r) const
	{
		return Compare(r) <= 0;
	}

	inline bool Date::operator>=(const Date& r) const
	{
		return Compare(r) >= 0;
	}

	inline Duration Date::operator-(const Date& r) const
	{
		return AgeBetween(r);
	}

	inline string Date::ToString() const
	{
		return IsEmpty() ? string() : DateStuff::ToString(m_Year, m_Month, m_Day);
	}

	inline Date Date::Today()
	{
		int y, m, d;
		DateStuff::Today(y, m, d);
		return Date(y, m, d);
	}

}
#endif