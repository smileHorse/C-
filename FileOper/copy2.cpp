
// 允许选择重定向的拷贝过滤器

#ifndef USE_CPLUSPLUS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char s[BUFSIZ];

	// 打开可选择的输入文件
	if (argc > 1)
	{
		if (freopen(argv[1], "r", stdin) == NULL)
		{
			return EXIT_FAILURE;
		}
	}

	// 打开可选择的输出文件
	if (argc > 2)
	{
		if (freopen(argv[2], "w", stdout) == NULL)
		{
			return EXIT_FAILURE;
		}
	}

	while(gets(s))
		puts(s);
	return EXIT_SUCCESS;
}

#else



#endif