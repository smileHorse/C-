
// ֻ�ܴӱ�׼�����ж��벢��ֻ��д����׼����ϵĳ������������

// ͨ�� FileOper.exe >file1 ��ʽִ�г��򣬽�������ַ����浽file1�ļ���

// ��һ�дӱ�׼���뿽������׼�����
#ifndef USE_CPLUSPLUS

#include <stdio.h>

int main1()
{
	// BUFSIZ��<stdio.h>�ж��壬ָ��������׼I/O������ʹ�õ��ڲ��������Ĵ�С��
	// ��ͬʱҲ���㻺������С������ѡ��
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
