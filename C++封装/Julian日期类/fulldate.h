#ifndef FULLDATE_H
#define FULLDATE_H

#include "date.h"

namespace DateStuff
{
	class FullDate : public Date
	{
	public:
		FullDate();
		FullDate(const string&);
		FullDate(int, int, int);
		FullDate(const Date&);

		bool IsValid() const;
		long ToJul() const;
	};

	inline FullDate::FullDate()
	{
		DateStuff::Today(m_Year, m_Month, m_Day);
	}

	inline bool FullDate::IsValid() const
	{
		return IsEmpty() || DateStuff::IsValidYMDay(m_Year, m_Month, m_Day);
	}

	inline long FullDate::ToJul() const
	{
		return GregToJul(m_Year, m_Month, m_Day);
	}
}

#endif