
// 定义下面两个宏，则将时间精度设置为纳秒，否则为微妙
//#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
//#define BOOST_DATE_TIME_SOURCE

#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <windows.h>

#include "basic_timer.h"

using namespace boost;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std;

int main()
{
	time_duration td(1, 10, 30, 1000);
	cout << td << endl;
	assert(td.hours() == 1 && td.minutes() == 10 && td.seconds() == 30);
	assert(td.total_seconds() == 1 * 3600 + 10 * 60 + 30);
	assert(td.total_milliseconds() == td.total_seconds() * 1000 + 1);
	assert(td.fractional_seconds() == 1000);
	assert(td.resolution() == date_time::micro);
	assert(td.num_fractional_digits() == 6);

	hours h(-10);
	assert(h.is_negative());
	time_duration h2 = h.invert_sign();
	assert(!h2.is_negative() && h2.hours() == 10);

	time_duration td1(not_a_date_time);
	assert(td1.is_special() && td1.is_not_a_date_time());

	time_duration td2(neg_infin);
	assert(td2.is_negative() && td2.is_neg_infinity());

	td1 = hours(1);
	td2 = hours(2) + minutes(30);
	assert(td1 < td2);
	assert((td1 + td2).hours() == 3);
	assert((td1 - td2).is_negative());
	assert(td1 * 5 == td2 * 2);
	assert((td1/2).minutes() == td2.minutes());

	cout << to_simple_string(td) << endl;
	cout << to_iso_string(td) << endl;

	// ptime
	ptime p(date(2010, 3, 5), hours(1));
	ptime p1 = time_from_string("2010-03-05 01:00:00");
	cout << p1 << endl;
	ptime p2 = from_iso_string("20100305T010000");
	cout << p2 << endl;
	p1 = second_clock::local_time();
	p2 = microsec_clock::universal_time();
	cout << p1 << endl << p2 << endl;

	ptime p3(not_a_date_time);
	assert(p3.is_not_a_date_time());
	ptime p4(pos_infin);
	assert(p4.is_special() && p4.is_pos_infinity());

	ptime p5(date(2010, 2, 14), hours(20));
	cout << to_simple_string(p5) << endl;
	cout << to_iso_string(p5) << endl;
	cout << to_iso_extended_string(p5) << endl;

	ptime p6 = from_time_t(std::time(0));
	assert(p6.date() == day_clock::local_day());

	FILETIME ft;
	ft.dwHighDateTime = 29715317;
	ft.dwLowDateTime = 3865122988UL;
	ptime p7 = from_ftime<ptime>(ft);

	ptimer t;

	return 0;
}