// 简单的四方向滚动的文件浏览器
// 按下面交互式命令打开文本文件
//	N	下一屏
//	P	前一屏
//	T	文件顶
//	B	文件底
//	L	向左滚动
//	R	向右滚动
//	Q,X	离开退出
// 

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
using namespace std;

namespace
{
	const int NROWS = 24;	// 屏幕的高度 - 1
	const int NCOLS = 79;	// 屏幕的宽度 - 1
	const int HORIZ = 20;	// 水平滚动增量

	// 当前屏幕的缓冲器
	char Screen[NROWS][NCOLS];
	size_t	Nlines;			// 显示行数
	size_t	Offset = 0;		// 水平的显示偏移量
	void read_a_screen(FILE* f)
	{
		clearerr(f);	// 重新安排可能的EOF条件
		for (int i = 0; i < NROWS && fgets(Screen[i], BUFSIZ, f); ++i)
		{
			Screen[i][strlen(Screen[i]) - 1] = '\0';
		}
		//Nlines = i;
	}
}