
// 通过显示的文件指针来拷贝文件

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

		// fgets区别于gets的地方在于fgets需要知道缓冲区的大小，gets只是假设有足够的空间。
		// 它一直读到比那些字符少1时为止，这样它能附加一个'\0',并且它能在所返回的字符串中保留这个换行字符(如果有空间的话是这样，而gets总是丢弃换行字符)
		// 它们各自配套的输出函数像所期望的那样执行：puts添加一个换行符给输出，而fputs则不。
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