#ifndef YEAR_H
#define YEAR_H

#include "DateStuff.h"

namespace DateStuff
{
	class Year
	{
	public:
		Year();	// ��ǰ����
		Year(int);
		Year(const string&);	// ȥ����ͷ��4������
		
		// ��ȡ��
		int GetYear() const;

		// �Ƚ�
		int Compare(const Year& right) const;
		bool operator==(const Year& right) const;
		bool operator!=(const Year& right) const;
		bool operator<(const Year& right) const;
		bool operator>(const Year& right) const;
		bool operator<=(const Year& right) const;
		bool operator>=(const Year& right) const;

		// ����
		int operator-(const Year& right) const;

		// ��������
		virtual void AddYears(int years);
		virtual void SubtractYears(int years);
		int YearsBetween(const Year& right) const;
		Duration AgeBetween(const Year& right) const;
		Duration Age() const;
		int EndOfYear() const;

		string ToString() const;
		bool IsValid() const;
		bool IsEmpty() const;

	protected:
		int m_Year;
	};

	inline int Year::GetYear() const
	{
		return m_Year;
	}

	inline int Year::Compare(const Year& right) const
	{
		return m_Year - right.m_Year;
	}

	inline bool Year::operator ==(const Year& right) const
	{
		return Compare(right) == 0;
	}

	inline bool Year::operator !=(const Year& right) const
	{
		return Compare(right) != 0;
	}

	inline bool Year::operator <(const Year& right) const
	{
		return Compare(right) < 0;
	}

	inline bool Year::operator >(const Year& right) const
	{
		return Compare(right) > 0;
	}

	inline bool Year::operator <=(const Year& right) const
	{
		return Compare(right) <= 0;
	}

	inline bool Year::operator >=(const Year& right) const
	{
		return Compare(right) >= 0;
	}

	inline int Year::operator -(const Year& right) const
	{
		return Compare(right);
	}

	inline Duration Year::AgeBetween(const Year& right) const
	{
		return Duration(YearsBetween(right));
	}

	inline int Year::YearsBetween(const Year& right) const
	{
		int diff = int(right.m_Year - m_Year);
		return int(diff >= 0 ? diff : -diff);
	}

	inline bool Year::IsValid() const
	{
		return MIN_YEAR <= m_Year && m_Year <= MAX_YEAR;
	}

	inline bool Year::IsEmpty() const
	{
		return m_Year == 0;
	}

	inline string Year::ToString() const
	{
		return IsEmpty() ? string() : DateStuff::ToString(m_Year, 0, 0);
	}
}
#endif