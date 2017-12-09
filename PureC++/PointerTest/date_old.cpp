// ������������֮��ĳ���ʱ��
#include <assert.h>
#include "date.h"

#define isleap(y)	((y) % 4 == 0 && (y) % 100 != 0 || (y) % 400 == 0)

// ƽ�������ÿ�µ�����
static int Daytab[2][13] = 
{
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

Date* date_interval(Date* d1, Date* d2)
{
	static Date result;
	int months, days, years, prev_month, year2;

	// ������ -- �ٶ�d1����d2
	years = d2->year - d1->year;
	assert(years >= 0);
	months = d2->month - d1->month;
	days = d2->day - d1->day;

	// �����Ե�����(����ǰ�����������)������ǰһ�����Ƕ�����ѭ������������<-28
	prev_month = d2->month - 1;
	year2 = d2->year;
	while(days < 0)
	{
		// ��ǰһ���½�
		if (prev_month == 0)
		{
			prev_month = 12;
			--year2;
		}
		--months;
		days += Daytab[isleap(year2)][prev_month--];
	}
	if (months < 0)
	{
		// ��ǰһ���
		--years;
		months += 12;
	}
	// ׼�����
	result.month = months;
	result.day = days;
	result.year = years;
	return &result;
}