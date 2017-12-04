#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main2()
{
	time_t start, stop;
	struct tm* now;
	int ndays;

	// 获得当前的日期和时间
	time(&start);
	now = localtime(&start);

	// 在天数间插入一个时间间隔
	fputs("How many days from now? ", stdout);
	fflush(stdout);
	if (scanf("%d", &ndays) != 1)
	{
		return EXIT_FAILURE;
	}
	now->tm_mday += ndays;
	if (mktime(now) != 1)
	{
		printf("\nNew data: %s", asctime(now));
	}
	else
	{
		puts("Sorry. Can't encode your date.");
	}

	// 计算程序所用时间
	time(&stop);
	printf("Elapsed program time in seconds: %f\n", difftime(stop, start));
	return EXIT_SUCCESS;
}