
#include "fulldate.h"

using namespace DateStuff;

DateStuff::FullDate::FullDate( const string& s )
{
	DateStuff::FromString(s, m_Year, m_Month, m_Day);
	if (!IsEmpty() && !IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
}

DateStuff::FullDate::FullDate( int year, int month, int day )
{
	m_Year = year;
	m_Month = month;
	m_Day = day;
	if (!IsEmpty() && !IsValidYMDay())
	{
		Throw(Date, DATE_ERROR);
	}
}

DateStuff::FullDate::FullDate( const Date& d )
{
	m_Year = d.GetYear();
	m_Month = d.GetMonth();
	m_Day = d.GetDay();
	assert(IsValid());
}
