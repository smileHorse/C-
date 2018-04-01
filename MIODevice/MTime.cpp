/********************************************************************
	created:	2018/04/01
	created:	1:4:2018   18:20
	filename: 	E:\GitProject\C-\MIODevice\MTime.cpp
	file path:	E:\GitProject\C-\MIODevice
	file base:	MTime
	file ext:	cpp
	author:		Masf
	
	purpose:	Time
*********************************************************************/

#include "MTime.h"

#include <locale.h>
#include <time.h>
#include <Windows.h>

MTime::MTime()
{
}

MTime::~MTime()
{

}


void MTime::start()
{
	*this = currentTime();
}


int MTime::restart()
{
	MTime t = currentTime();
	int n = msecsTo(t);
	if (n < 0)                                // passed midnight
		n += 86400*1000;
	*this = t;
	return n;
}

int MTime::elapsed() const
{
	int n = msecsTo(currentTime());
	if (n < 0)                                // passed midnight
		n += 86400 * 1000;
	return n;
}

int MTime::hour() const
{
	return ds() / MSECS_PER_HOUR;
}

int MTime::minute() const
{
	return (ds() % MSECS_PER_HOUR) / MSECS_PER_MIN;
}

int MTime::second() const
{
	return (ds() / 1000)%SECS_PER_MIN;
}

int MTime::msec() const
{
	return ds() % 1000;
}


int MTime::msecsTo( const MTime& t ) const
{
	return t.ds() - ds();
}

MTime MTime::currentTime()
{
	MTime ct;
	SYSTEMTIME st;
	memset(&st, 0, sizeof(SYSTEMTIME));
	GetLocalTime(&st);
	ct.setHMS(st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	return ct;
}

bool MTime::setHMS( int h, int m, int s, int ms )
{
	mds = (h*SECS_PER_HOUR + m*SECS_PER_MIN + s)*1000 + ms;
	return true;
}
