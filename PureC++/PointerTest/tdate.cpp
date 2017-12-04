// ����date_internal
#include <stdio.h>
#include "date.h"

int main4()
{
	Date d1, d2, *result;

	// ������������ -- �ٶ���һ�����ڵڶ���
	fputs("Enter a date, MM/DD/YY> ", stdout);
	fflush(stdout);
	if (scanf("%d/%d/%d%*c", &d1.month, &d1.day, &d1.year) != 3)
	{
		return 1;
	}

	fputs("Enter a later date, MM/DD/YY> ", stdout);
	fflush(stdout);
	if (scanf("%d/%d/%d%*c", &d2.month, &d2.day, &d2.year) != 3)
	{
		return 1;
	}

	// ���������յļ��
	result = date_interval(&d1, &d2);
	printf("years: %d, months: %d, days: %d\n", result->year, result->month, result->day);
	return 0;
}