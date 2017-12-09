
// 带有错误检测的 copy3

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

		// fgets区别于gets的地方在于fgets需要知道缓冲区的大小，gets只是假设有足够的空间。
		// 它一直读到比那些字符少1时为止，这样它能附加一个'\0',并且它能在所返回的字符串中保留这个换行字符(如果有空间的话是这样，而gets总是丢弃换行字符)
		// 它们各自配套的输出函数像所期望的那样执行：puts添加一个换行符给输出，而fputs则不。
		while(fgets(s, BUFSIZ, inf))
		{
			fputs(s, outf);
			fflush(outf);

			// fgets和gets在进行到文件结尾或出错时都返回NULL，通常不需要有任何另外的错误检查。
			// 然而，应该显示地检查输出错误。因为在PC系统中用完磁盘空间是很常见的。通过调用ferror来做错误检验。
			// 由于文件I/O是缓冲的，因此必须在进行错误检查之前刷新输出缓冲。一旦文件的错误状态被设置了，它保持这个状态不变直到通过调用clearerr或者rewind来复位它。
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