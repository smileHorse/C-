/************************************************************************/
/* ����ָ������̬�����ļ�                                                */
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

// ���������ļ�
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

// �õ�Ŀ¼�����е��ļ�����
void getFileNames(const string& dirName, vector<string>& fileNames)
{
	_finddata_t file;
	long lf;
	//�����ļ���·��  
	if ((lf = _findfirst(dirName.c_str(), &file)) == -1) {
		cout << dirName << " not found!!!" << endl;
	}
	else {
		while (_findnext(lf, &file) == 0) {
			//����ļ���  
			//cout<<file.name<<endl;  
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
				continue;
			fileNames.push_back(file.name);
		}
	}
	_findclose(lf);
}

// ���ļ������л�ȡ�����
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
	// ���������ļ�
	//createTestFile();

	// ָ���ļ���
	string dirName = "./dir/*.und";

	// ���Ҹ��ļ����µ������ļ�
	vector<string> fileNames;
	getFileNames(dirName, fileNames);

	// ��ȡ�����ļ��������
	int no = getMaxNo(fileNames);

	// �����µ��ļ���
	string newName = PREFIX + to_string(no) + SUFFIX;

	cout << "create new fileName " << newName << endl;

	return 0;
}