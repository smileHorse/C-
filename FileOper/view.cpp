// �򵥵��ķ���������ļ������
// �����潻��ʽ������ı��ļ�
//	N	��һ��
//	P	ǰһ��
//	T	�ļ���
//	B	�ļ���
//	L	�������
//	R	���ҹ���
//	Q,X	�뿪�˳�
// 

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
using namespace std;

namespace
{
	const int NROWS = 24;	// ��Ļ�ĸ߶� - 1
	const int NCOLS = 79;	// ��Ļ�Ŀ�� - 1
	const int HORIZ = 20;	// ˮƽ��������

	// ��ǰ��Ļ�Ļ�����
	char Screen[NROWS][NCOLS];
	size_t	Nlines;			// ��ʾ����
	size_t	Offset = 0;		// ˮƽ����ʾƫ����
	void read_a_screen(FILE* f)
	{
		clearerr(f);	// ���°��ſ��ܵ�EOF����
		for (int i = 0; i < NROWS && fgets(Screen[i], BUFSIZ, f); ++i)
		{
			Screen[i][strlen(Screen[i]) - 1] = '\0';
		}
		//Nlines = i;
	}
}