/********************************************************************
	created:	2018/04/01
	created:	1:4:2018   18:20
	filename: 	E:\GitProject\C-\MIODevice\MTime.h
	file path:	E:\GitProject\C-\MIODevice
	file base:	MTime
	file ext:	h
	author:		Masf
	
	purpose:	Time
*********************************************************************/
#ifndef MTIME_H
#define MTIME_H

#include <ctime>

class MTime
{
public:
	MTime();
	~MTime();

	enum {
		SECS_PER_DAY = 86400,
		MSECS_PER_DAY = 86400000,
		SECS_PER_HOUR = 3600,
		MSECS_PER_HOUR = 3600000,
		SECS_PER_MIN = 60,
		MSECS_PER_MIN = 60000,
		TIME_T_MAX = 2145916799,  // int maximum 2037-12-31T23:59:59 UTC
		JULIAN_DAY_FOR_EPOCH = 2440588 // result of julianDayFromDate(1970, 1, 1)
	};

	void start();
	int restart();
	int elapsed() const;

	int hour() const;
	int minute() const;
	int second() const;
	int msec() const;

	int msecsTo(const MTime &) const;

	static MTime currentTime();

private:
	bool setHMS(int h, int m, int s, int ms);

	inline int ds() const { return mds == -1 ? 0 : mds; }

private:
	int mds;
};

#endif
