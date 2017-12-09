#include "date.h"

using namespace DateStuff;

DateStuff::Date::Date( int y/*= 0*/, int m/*= 0*/, int d/*= 0*/ )
{
	m_Year = y;
	m_Month = m;
	m_Day = d;
	if (!IsEmpty() && !IsValid())
	{
		Throw(Date, DATE_ERROR);
	}
}

DateStuff::Date::Date( const string& s )
{
	// 需要yyyymmdd剩下的子集
	if (s.size() > 8)
	{
		Throw2(Date, DATE_ERROR, "String too long");
	}
	
	m_Year = (s.size() >= 4) ? int(atoi(s.substr(0, 4).c_str())) : 0;
	m_Month = (s.size() >= 6) ? int(atoi(s.substr(4, 2).c_str())) : 0;
	m_Day = (s.size() >= 8) ? int(atoi(s.substr(6, 2).c_str())) : 0;
	if (!IsEmpty() && !IsValid())
	{
		Throw(Date, DATE_ERROR);
	}
}

Date& DateStuff::Date::operator=( const string& s )
{
	// 需要yyyymmdd剩下的子集
	if (s.size() > 8)
	{
		Throw2(Date, DATE_ERROR, "String too long");
	}

	m_Year = int(atoi(s.substr(0, 4).c_str()));
	m_Month = int(atoi(s.substr(4, 2).c_str()));
	m_Day = int(atoi(s.substr(6, 2).c_str()));
	if (!IsEmpty() && !IsValid())
	{
		Throw(Date, DATE_ERROR);
	}
	return *this;
}


void DateStuff::Date::AddYears( int years )
{
	if (IsValidYMDay())
	{
		DateStuff::AddYears(years, m_Year, m_Month, m_Day);
	}
	else if (IsValidYMonth() || IsValidYear())
	{
		Year y(m_Year);
		y.AddYears(years);
		operator=(y);
	}
	else
	{
		Throw(Date, DATE_ERROR);
	}
}

void DateStuff::Date::SubtractYears( int years )
{
	if (IsValidYMDay())
	{
		DateStuff::SubtractYears(years, m_Year, m_Month, m_Day);
	}
	else if (IsValidYMonth() || IsValidYear())
	{
		Year y(m_Year);
		y.SubtractYears(years);
		operator=(y);
	}
	else
	{
		Throw(Date, DATE_ERROR);
	}
}


int DateStuff::Date::YearsBetween( const Date& r ) const
{
	if (!IsValid())
	{
		Throw(Date, DATE_ERROR);
	}
	Year me(m_Year);
	Year you(r.m_Year);
	return me.YearsBetween(you);
}

void DateStuff::Date::AddMonths( long months )
{
	if (IsValidYMDay())
	{
		DateStuff::AddMonths(months, m_Year, m_Month, m_Day);
	}
	else if (IsValidYMonth())
	{
		DateStuff::ResolveMonths(m_Year * 12L + m_Month + months, m_Year, m_Month);
	}
	else
	{
		Throw(Date, DATE_ERROR);
	}
}

void DateStuff::Date::SubtractMonths( long months )
{
	if (IsValidYMDay())
	{
		DateStuff::SubtractMonths(months, m_Year, m_Month, m_Day);
	}
	else if (IsValidYMonth())
	{
		DateStuff::ResolveMonths(m_Year * 12L + m_Month - months, m_Year, m_Month);
	}
	else
	{
		Throw(Date, DATE_ERROR);
	}
}

long DateStuff::Date::MonthsBetween( const Date& r ) const
{
	if (!IsValidYMDay() || !r.IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::MonthsBetween(m_Year, m_Month, r.m_Year, r.m_Month);
}

void DateStuff::Date::AddDays( long days )
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::AddDays(days, m_Year, m_Month, m_Day);
}

void DateStuff::Date::SubtractDays( long days )
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::SubtractDays(days, m_Year, m_Month, m_Day);
}

long DateStuff::Date::DaysBetween( const Date& r ) const
{
	if (!IsValidYMDay() || !r.IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::DaysBetween(m_Year, m_Month, m_Day, r.m_Year, r.m_Month, r.m_Day);
}

void DateStuff::Date::AddWeeks( long weeks )
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::AddWeeks(weeks, m_Year, m_Month, m_Day);
}

void DateStuff::Date::SubtractWeeks( long weeks )
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::SubtractWeeks(weeks, m_Year, m_Month, m_Day);
}

long DateStuff::Date::WeeksBetween( const Date& r ) const
{
	if (!IsValidYMDay() || !r.IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::WeeksBetween(m_Year, m_Month, m_Day, r.m_Year, r.m_Month, r.m_Day);
}

void DateStuff::Date::AddWeekDays( long days )
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::AddWeekDays(days, m_Year, m_Month, m_Day);
}

void DateStuff::Date::SubtractWeekDays( long days )
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::SubtractWeekDays(days, m_Year, m_Month, m_Day);
}

long DateStuff::Date::WeekDaysBetween( const Date& r ) const
{
	if (!IsValidYMDay() || !r.IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::WeekDaysBetween(m_Year, m_Month, m_Day, r.m_Year, r.m_Month, r.m_Day);
}

int DateStuff::Date::DayOfWeek() const
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::DayOfWeek(m_Year, m_Month, m_Day);
}

int DateStuff::Date::DayOfYear() const
{
	if (!IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::DayOfYear(m_Year, m_Month, m_Day);
}

int DateStuff::Date::EndOfMonth() const
{
	if (!IsValidYear())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::EndOfMonth(m_Year, m_Month);
}

int DateStuff::Date::EndOfYear() const
{
	if (!IsValidYear())
	{
		Throw(Date, DATE_ERROR);
	}
	return DateStuff::EndOfYear(m_Year);
}

DateStuff::Duration DateStuff::Date::AgeBetween( const Date& r ) const
{
	if (!IsValid() || !r.IsValid())
	{
		Throw(Date, DATE_ERROR);
	}

	if (IsValidYMDay() && r.IsValidYMDay())
	{
		return DateStuff::AgeBetween(m_Year, m_Month, m_Day, r.m_Year, r.m_Month, r.m_Day);
	}
	else if (IsValidYMonth() && r.IsValidYMonth())
	{
		return DateStuff::AgeBetween(m_Year, m_Month, 0, r.m_Year, r.m_Month, 0);
	}
	else if (IsValidYear() && r.IsValidYear())
	{
		return DateStuff::AgeBetween(m_Year, 0, 0, r.m_Year, 0, 0);
	}
	else
	{
		// 不应在这里获得
		assert(0);
		return Duration(-1, -1, -1);
	}
}

DateStuff::Duration DateStuff::Date::Age() const
{
	return AgeBetween(Today());
}