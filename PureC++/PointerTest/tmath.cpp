#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main2()
{
	time_t start, stop;
	struct tm* now;
	int ndays;

	// ��õ�ǰ�����ں�ʱ��
	time(&start);
	now = localtime(&start);

	// �����������һ��ʱ����
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

	// �����������ʱ��
	time(&stop);
	printf("Elapsed program time in seconds: %f\n", difftime(stop, start));
	return EXIT_SUCCESS;
}