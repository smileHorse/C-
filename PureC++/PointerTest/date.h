#ifndef DATE_H
#define DATE_H

// ���ڵļ򵥱���
struct DATE
{
	int year;		// ȫ�����ڣ�1992
	int month;		// 1 - 12
	int day;		// 1 - 31
};
typedef struct DATE Date;

Date* date_interval(Date*, Date*);
#endif