
// 拷贝二进制文件
// 在MSDOS的文本模式下，内存中的每一个换行字符在输出设备中都被"\r\n"替换，然而在输入时与这个过程相反(这是从过去的CP/M时代继承下来的)。
// 此外，CTRL+Z被解释成文件结束，因此在文本模式下不可能跳过Ctrl+Z来读入数据。
// 在二进制模式下没有那么多的翻译产生 -- 在内存中的数据和在磁盘中的数据是一样的。

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

		// fread和fwrite分别对数据块进行读和写操作，它们返回已经成功处理的数据块(不是字节)的数量。
		// 在这个例子中，各项恰巧是以字节出现的(即长度为1的模块)。
		// 当fwrite返回值小于各项要求的数量时，就知道发生了写错误，在这种情况下没有必要显示地调用ferror。
		// 任何由fwrite写入的非字符数据都在输出设备中以二进制模式存储，肉眼通常看不见它
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

		// read和write方法与fread、fwrite作用相似
		// istream::gcount返回“所得到的的数”，即由istream::read传递的字节数
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