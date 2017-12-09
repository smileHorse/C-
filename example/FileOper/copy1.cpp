
// 只能从标准输入中读入并且只能写到标准输出上的程序叫做过滤器

// 通过 FileOper.exe >file1 形式执行程序，将输入的字符保存到file1文件中

// 把一行从标准输入拷贝到标准输出中
#ifndef USE_CPLUSPLUS

#include <stdio.h>

int main1()
{
	// BUFSIZ在<stdio.h>中定义，指的是许多标准I/O函数中使用的内部缓冲区的大小。
	// 它同时也是你缓冲区大小的理想选择
	char s[BUFSIZ];

	while(gets(s))
		puts(s);
	return 0;
}

#else

/* C++ Version*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;

	while(getline(cin, s))
		cout << s << endl;
}

#endif
