#ifndef YMONTH_H
#define YMONTH_H

#include "year.h"

namespace DateStuff
{
	class YMonth : public Year
	{
		typedef Year Super;

	public:
		YMonth();
		YMonth(int y, int m);
		YMonth(const string& s);

		// 存取器
		int GetMonth() const;

		// 比较
		int Compare(const YMonth& right) const;
		bool operator==(const YMonth& right) const;
		bool operator!=(const YMonth& right) const;
		bool operator<(const YMonth& right) const;
		bool operator>(const YMonth& right) const;
		bool operator<=(const YMonth& right) const;
		bool operator>=(const YMonth& right) const;

		// 计算
		int operator-(const YMonth& right) const;

		// 其他操作
		virtual void AddMonths(long months);
		virtual void SubtractMonths(long months);
		long MonthsBetween(const YMonth& right) const;
		Duration AgeBetween(const YMonth& right) const;
		Duration Age() const;
		int EndOfYear() const;
		int EndOfMonth() const;
		int DaysInPrevMonth() const;
		int DaysInNextMonth() const;

		string ToString() const;
		bool IsValid() const;
		bool IsEmpty() const;

		static Duration AgeBetween(const YMonth& first, const YMonth& last);

	protected:
		int m_Month;

	private:
		void Resolve(long months);
	};

	inline int YMonth::GetMonth() const
	{
		return m_Month;
	}

	inline int YMonth::Compare(const YMonth& right) const
	{
		int diff = Super::Compare(right);
		return (diff == 0) ? m_Month - right.m_Month : diff;
	}

	inline bool YMonth::operator ==(const YMonth& right) const
	{
		return Compare(right) == 0;
	}

	inline bool YMonth::operator !=(const YMonth& right) const
	{
		return Compare(right) != 0;
	}

	inline bool YMonth::operator <(const YMonth& right) const
	{
		return Compare(right) < 0;
	}

	inline bool YMonth::operator >(const YMonth& right) const
	{
		return Compare(right) > 0;
	}

	inline bool YMonth::operator <=(const YMonth& right) const
	{
		return Compare(right) <= 0;
	}

	inline bool YMonth::operator >=(const YMonth& right) const
	{
		return Compare(right) >= 0;
	}

	inline int YMonth::operator -(const YMonth& right) const
	{
		return (m_Year - right.m_Year) * 12L + m_Month - right.m_Month; 
	}

	inline long YMonth::MonthsBetween(const YMonth& right) const
	{
		long diff = (right - *this);
		return diff >= 0 ? diff : -diff;
	}

	inline void YMonth::AddMonths(long months)
	{
		Resolve(m_Year * 12L + m_Month - months);
	}

	inline void YMonth::SubtractMonths(long months)
	{
		Resolve(m_Year * 12L + m_Month - months);
	}

	inline Duration YMonth::AgeBetween(const YMonth& right) const
	{
		return AgeBetween(right, *this);
	}

	inline bool YMonth::IsValid() const
	{
		return Super::IsValid() && 
			1 <= m_Month && m_Month <= 12;
	}

	inline bool YMonth::IsEmpty() const
	{
		return Super::IsEmpty() && m_Month == 0;
	}

	inline string YMonth::ToString() const
	{
		char buf[23];	// 2个整型数 + 1
		sprintf(buf, "%04d%02d", m_Year, m_Month);
		return IsEmpty() ? string() : string(buf);
	}

	inline void YMonth::Resolve(long months)
	{
		DateStuff::ResolveMonths(months, m_Year, m_Month);
	}

	inline Duration YMonth::AgeBetween(const YMonth& first, const YMonth& last)
	{
		return DateStuff::AgeBetween(first.m_Year, first.m_Month, 0, last.m_Year, last.m_Month, 0);
	}
}
#endif