
// �����������ļ�
// ��MSDOS���ı�ģʽ�£��ڴ��е�ÿһ�������ַ�������豸�ж���"\r\n"�滻��Ȼ��������ʱ����������෴(���Ǵӹ�ȥ��CP/Mʱ���̳�������)��
// ���⣬CTRL+Z�����ͳ��ļ�������������ı�ģʽ�²���������Ctrl+Z���������ݡ�
// �ڶ�����ģʽ��û����ô��ķ������ -- ���ڴ��е����ݺ��ڴ����е�������һ���ġ�

#ifndef USE_CPLUSPLUS

#include <stdio.h>
#include <stdlib.h>

int main5(int argc, char* argv[])
{
	if (argc == 3)
	{
		char buf[BUFSIZ];
		FILE	*inf, *outf;

		if ((inf = fopen(argv[1], "rb")) == NULL)
		{
			return EXIT_FAILURE;
		}
		if ((outf = fopen(argv[2], "wb")) == NULL)
		{
			return EXIT_FAILURE;
		}

		// fread��fwrite�ֱ�����ݿ���ж���д���������Ƿ����Ѿ��ɹ���������ݿ�(�����ֽ�)��������
		// ����������У�����ǡ�������ֽڳ��ֵ�(������Ϊ1��ģ��)��
		// ��fwrite����ֵС�ڸ���Ҫ�������ʱ����֪��������д���������������û�б�Ҫ��ʾ�ص���ferror��
		// �κ���fwriteд��ķ��ַ����ݶ�������豸���Զ�����ģʽ�洢������ͨ����������
		while(!feof(inf))
		{
			int nitems = fread(buf, 1, BUFSIZ, inf);
			if (fwrite(buf, 1, nitems, outf) != nitems)
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

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		char buf[BUFSIZ];
		ifstream inf(argv[1], ios::in | ios::binary);
		ofstream outf(argv[2], ios::out | ios::binary);

		// read��write������fread��fwrite��������
		// istream::gcount���ء����õ��ĵ�����������istream::read���ݵ��ֽ���
		while(inf)
		{
			inf.read(buf, BUFSIZ);
			outf.write(buf, inf.gcount());
			if (!outf)
			{
				return EXIT_FAILURE;
			}
		}
		return inf.fail() ? EXIT_FAILURE : EXIT_SUCCESS;
	}
	else
	{
		return EXIT_FAILURE;
	}
}

#endif