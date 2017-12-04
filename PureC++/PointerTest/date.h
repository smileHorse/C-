#ifndef DATE_H
#define DATE_H

// 日期的简单编码
struct DATE
{
	int year;		// 全部日期：1992
	int month;		// 1 - 12
	int day;		// 1 - 31
};
typedef struct DATE Date;

Date* date_interval(Date*, Date*);
#endif