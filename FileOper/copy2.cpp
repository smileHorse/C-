
// ����ѡ���ض���Ŀ���������

#ifndef USE_CPLUSPLUS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char s[BUFSIZ];

	// �򿪿�ѡ��������ļ�
	if (argc > 1)
	{
		if (freopen(argv[1], "r", stdin) == NULL)
		{
			return EXIT_FAILURE;
		}
	}

	// �򿪿�ѡ�������ļ�
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