// 从文件递归的读取参数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CHUNK	10	// 重新分配的数量
static char** args;	// 参数列表
static int nleft;	// 不用的参数位置
static int nargs;	// 参数的数量

// 私有函数
static void expand(FILE* f);
static void add(char* arg);

char** arglist(int old_nargs, char** old_args, int* new_nargs)
{
	int i;

	// 最初的分配
	args = (char**)calloc(old_nargs, sizeof(char*));
	assert(args);
	nleft = old_nargs;
	nargs = 0;

	// 处理每个命令行的参数
	for (i = 0; i < old_nargs; ++i)
	{
		if (old_args[i][0] == '@')
		{
			// 打开参数文件
			FILE* f = fopen(old_args[i] + 1, "r");
			if (f)
			{
				expand(f);
				fclose(f);
			}
		}
		else
		{
			add(old_args[i]);
		}
	}

	*new_nargs = nargs;
	return args;
}

void free_arglist(int n, char** av)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		free(av[i]);
	}
	free(av);
}

static void expand(FILE* f)
{
	char token[BUFSIZ];

	while(fscanf(f, "%s", token) == 1)
	{
		if (token[0] == '@')
		{
			FILE* g = fopen(token + 1, "r");
			if (g)
			{
				expand(g);
				fclose(g);
			}
		}
		else
		{
			add(token);
		}
	}
}

static void add(char* arg)
{
	if (nleft == 0)
	{
		// 扩大参数列表
		args = (char**)realloc(args, (nargs + CHUNK) * sizeof(char*));
		assert(args);
		nleft = CHUNK;
	}

	// 为存储参数分配空间
	args[nargs] = (char*)malloc(strlen(arg) + 1);
	assert(args[nargs]);
	strcpy(args[nargs], arg);
	--nleft;
}