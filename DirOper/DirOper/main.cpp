/************************************************************************/
/* 按照指定规则动态创建文件                                                */
/************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <direct.h>  
#include <io.h>  

using namespace std;

#define PREFIX "ht_"
#define SUFFIX "..und"

// 创建测试文件
void createTestFile()
{
	string dirName = "./dir/";
	for (int i = 0; i < 5000; ++i)
	{
		string fileName = dirName + PREFIX + to_string(i) + SUFFIX;
		FILE* fd = fopen(fileName.c_str(), "w");
		if (fd != NULL)
		{
			fclose(fd);
		}
	}
}

// 得到目录中所有的文件名称
void getFileNames(const string& dirName, vector<string>& fileNames)
{
	_finddata_t file;
	long lf;
	//输入文件夹路径  
	if ((lf = _findfirst(dirName.c_str(), &file)) == -1) {
		cout << dirName << " not found!!!" << endl;
	}
	else {
		while (_findnext(lf, &file) == 0) {
			//输出文件名  
			//cout<<file.name<<endl;  
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
				continue;
			fileNames.push_back(file.name);
		}
	}
	_findclose(lf);
}

// 从文件名称中获取最大编号
int getMaxNo(const vector<string>& fileNames)
{
	int no = -1;
	string prefix = PREFIX;
	string suffix = SUFFIX;
	for (const string& fileName : fileNames)
	{
		size_t prefixPos = fileName.find(prefix);
		size_t suffixPos = fileName.find(suffix);
		if (prefixPos != string::npos && suffixPos != string::npos)
		{
			size_t startIndex = prefixPos + prefix.length();
			string strNo = fileName.substr(startIndex, suffixPos - startIndex);
			if (stoi(strNo) > no)
			{
				no = stoi(strNo);
			}
		}
	}
	return ++no;
}

int main()
{
	// 创建测试文件
	//createTestFile();

	// 指定文件夹
	string dirName = "./dir/*.und";

	// 查找该文件夹下的所有文件
	vector<string> fileNames;
	getFileNames(dirName, fileNames);

	// 获取所有文件的最大编号
	int no = getMaxNo(fileNames);

	// 生成新的文件名
	string newName = PREFIX + to_string(no) + SUFFIX;

	cout << "create new fileName " << newName << endl;

	return 0;
}