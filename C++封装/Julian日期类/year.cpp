#include "year.h"
#include <time.h>

using namespace DateStuff;

DateStuff::Year::Year()
{
	// 获得当前的年
	time_t tval = time(0);
	struct tm* tmp = localtime(&tval);

	m_Year = int(tmp->tm_year + 1900);
}

DateStuff::Year::Year( int y )
{
	m_Year = y;
	if (!IsEmpty() && !IsValid())
	{
		Throw(Date, YEAR_ERROR);
	}
}

DateStuff::Year::Year( const string& s )
{
	m_Year = atoi(s.substr(0, 4).c_str());
	if (!IsEmpty() && !IsValid())
	{
		Throw(Date, YEAR_ERROR);
	}
}

void DateStuff::Year::AddYears( int years )
{
	if (m_Year > MAX_YEAR - years)
	{
		Throw(Date, YEAR_ERROR);
	}

	m_Year += years;
}

void DateStuff::Year::SubtractYears( int years )
{
	if (m_Year < MIN_YEAR + years)
	{
		Throw(Date, RANGE_ERROR);
	}
	m_Year -= years;
}

DateStuff::Duration DateStuff::Year::Age() const
{
	return AgeBetween(Year());
}

int DateStuff::Year::EndOfYear() const
{
	if (!IsValid())
	{
		Throw(Date, YEAR_ERROR);
	}
	return DateStuff::EndOfYear(m_Year);
}