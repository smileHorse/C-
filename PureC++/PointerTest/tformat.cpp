#include <stdio.h>
#include <time.h>

int main3()
{
	time_t tval;
	struct tm* now;
	char buf[BUFSIZ];
	char* fancy_format = "Or getting really fancy: \n"
						"Today is %A, %B %d, day %j of %Y, \n"
						"and the time is %I:%M %p";

	// 获得当前的日期和时间
	tval = time(NULL);
	now = localtime(&tval);

	printf("The current date and time: %d/%02d/%02d %d:%02d:%02d\n\n", 
		now->tm_mon + 1, now->tm_mday, now->tm_year + 1900, 
		now->tm_hour, now->tm_min, now->tm_sec);
	printf("Or in default, system format: %s\n", ctime(&tval));
	strftime(buf, sizeof buf, fancy_format, now);
	puts(buf);
	return 0;
}