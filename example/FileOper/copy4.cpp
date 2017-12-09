
// ���д������ copy3

#ifndef USE_CPLUSPLUS

#include <stdio.h>
#include <stdlib.h>

int main4(int argc, char* argv[])
{
	if (argc == 3)
	{
		char s[BUFSIZ];
		FILE	*inf, *outf;
		if ((inf = fopen(argv[1], "r")) == NULL)
		{
			return EXIT_FAILURE;
		}
		if ((outf = fopen(argv[2], "w")) == NULL)
		{
			return EXIT_FAILURE;
		}

		// fgets������gets�ĵط�����fgets��Ҫ֪���������Ĵ�С��getsֻ�Ǽ������㹻�Ŀռ䡣
		// ��һֱ��������Щ�ַ���1ʱΪֹ���������ܸ���һ��'\0',���������������ص��ַ����б�����������ַ�(����пռ�Ļ�����������gets���Ƕ��������ַ�)
		// ���Ǹ������׵����������������������ִ�У�puts���һ�����з����������fputs�򲻡�
		while(fgets(s, BUFSIZ, inf))
		{
			fputs(s, outf);
			fflush(outf);

			// fgets��gets�ڽ��е��ļ���β�����ʱ������NULL��ͨ������Ҫ���κ�����Ĵ����顣
			// Ȼ����Ӧ����ʾ�ؼ�����������Ϊ��PCϵͳ��������̿ռ��Ǻܳ����ġ�ͨ������ferror����������顣
			// �����ļ�I/O�ǻ���ģ���˱����ڽ��д�����֮ǰˢ��������塣һ���ļ��Ĵ���״̬�������ˣ����������״̬����ֱ��ͨ������clearerr����rewind����λ����
			if (ferror(outf))
			{
				return EXIT_FAILURE;
			}
		}

		fclose(inf);
		fclose(outf);
		return EXIT_SUCCESS;
	}
	else
	{
		return EXIT_FAILURE;
	}
}

#else



#endif