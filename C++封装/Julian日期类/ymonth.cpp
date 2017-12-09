#include "ymonth.h"
#include <time.h>

using namespace DateStuff;

DateStuff::YMonth::YMonth()
{
	// 获得当前的月
	time_t tval = time(0);
	struct tm* tmp = localtime(&tval);

	m_Month = int(tmp->tm_mon + 1);
}

DateStuff::YMonth::YMonth( int y, int m )
	: Year(y)
{
	m_Month = m;
	if (!IsEmpty() && !IsValid())
	{
		Throw(Date, MONTH_ERROR);
	}
}

DateStuff::YMonth::YMonth( const string& s )
	: Year(s)
{
	m_Month = int(atoi(s.substr(4, 2).c_str()));
	if (!IsEmpty() && !IsValid())
	{
		Throw(Date, MONTH_ERROR);
	}
}

DateStuff::Duration DateStuff::YMonth::Age() const
{
	return AgeBetween(*this, YMonth());
}

int DateStuff::YMonth::EndOfYear() const
{
	if (!IsValid())
	{
		Throw(Date, MONTH_ERROR);
	}
	return DateStuff::EndOfYear(m_Year);
}

int DateStuff::YMonth::EndOfMonth() const
{
	if (!IsValid())
	{
		Throw(Date, MONTH_ERROR);
	}
	return DateStuff::EndOfMonth(m_Year, m_Month);
}

int DateStuff::YMonth::DaysInPrevMonth() const
{
	if (!IsValid())
	{
		Throw(Date, MONTH_ERROR);
	}
	return DateStuff::DaysInPrevMonth(m_Year, m_Month);
}

int DateStuff::YMonth::DaysInNextMonth() const
{
	if (!IsValid())
	{
		Throw(Date, MONTH_ERROR);
	}
	return DateStuff::DaysInNextMonth(m_Year, m_Month);
}