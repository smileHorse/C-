// 处理有固定长度记录的文件

/*
函数fread和fwrite适合处理有固定长度记录的文件。
在打开模式请求中的“+”表示更新模式，这意味着允许文件的输入和输出。然而，必须通过调用fflush或者一些文件定位命令如fseek和rewind，来分隔输入操作和输出操作。
命令fseek把读/写光标定位在从文件开头开始数的给定数量的字节上(SEEK_SET)，或从文件结尾开始数的给定数量的字节上(SEEK_END),或从当前位置开始数的给定数量的字节上(SEEK_CUR).
命令rewind等价于fseek(f, 0L, SEEK_SET)。
传递给fseek的任意字节定位只有在二进制模式下才有意义，因为在文本模式下可能存在未知的嵌入式字符。
函数ftell返回在一个文件中光标的当前位置，这个值可以被传递给fseek以返回到那个位置。(这种fseek和ftell的同步应用也可以在文本模式下使用)。
由于fseek和ftell为了文件定位而采用一个长整型参数，它们被自己能正确遍历文件的大小所限制。如果系统支持更大的文件定位值，可以通过库函数fgetpos和fsetpos随机地遍历这些文件，
它们与fpos_t类型的值进行交易，fpos_t类型可能是整型值也可能不是。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXRECS	10

struct record
{
	char last[16];
	char first[11];
	int age;
};

static char* get_field(char *, char *);

int main6()
{
	int nrecs;
	char s[81];
	struct record recs[MAXRECS], recbuf;
	FILE* f;

	// 小心地保存记录
	for (nrecs = 0; nrecs < MAXRECS && get_field("Last", s); ++nrecs)
	{
		strncpy(recs[nrecs].last, s, 15)[15] = '\0';
		get_field("First", s);
		strncpy(recs[nrecs].first, s, 10)[10] = '\0';
		get_field("Age", s);
		recs[nrecs].age = atoi(s);
	}

	// 将记录写入文件
	if ((f = fopen("recs.dat", "w+b")) == NULL)
	{
		return EXIT_FAILURE;
	}
	if (fwrite(recs, sizeof(recs[0]), nrecs, f) != nrecs)
	{
		return EXIT_FAILURE;
	}

	// 定位于最后一条记录
	fseek(f, (nrecs - 1) * sizeof(struct record), SEEK_SET);
	fread(&recbuf, 1, sizeof(struct record), f);
	printf("last: %s, first: %s, age: %d\n", recbuf.last, recbuf.first, recbuf.age);

	// 定位于第一条记录
	rewind(f);
	fread(&recbuf, 1, sizeof(struct record), f);
	printf("last: %s, first: %s, age: %d\n", recbuf.last, recbuf.first, recbuf.age);

	return EXIT_SUCCESS;
}

static char* get_field(char* prompt, char* buf)
{
	// 为输入域提示
	fprintf(stderr, "%s: ", prompt);
	return gets(buf);
}