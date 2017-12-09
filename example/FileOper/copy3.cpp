
// ͨ����ʾ���ļ�ָ���������ļ�

#ifndef USE_CPLUSPLUS

#include <stdio.h>
#include <stdlib.h>

int main3(int argc, char* argv[])
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
			fputs(s, outf);

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

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		string s;
		ifstream inf(argv[1]);
		ofstream outf(argv[2]);
		if (!inf || !outf)
		{
			return EXIT_FAILURE;
		}

		while(getline(inf, s))
			outf << s << endl;
	}
}

#endif