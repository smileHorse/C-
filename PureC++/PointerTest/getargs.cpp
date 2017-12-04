// 读参数文件

#include <stdio.h>

extern char** arglist(int, char**, int*);
extern void free_arglist(int, char**);

int main2(int argc, char* argv[])
{
	int i, nargs;
	char** args = arglist(--argc, ++argv, &nargs);

	for (i = 0; i < nargs; ++i)
	{
		printf("%d: %s\n", i, args[i]);
	}
	free_arglist(nargs, args);
	return 0;
}