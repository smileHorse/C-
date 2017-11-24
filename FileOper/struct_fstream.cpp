
// 使用fstream操作带string的结构体的二进制文件读写
#include <fstream>
#include <iostream>

#include "StructWithString.h"

using namespace std;

#define FILE_TITLE	"struct_fstream.msg"

extern void initStrRecords(StructWithStringSeq& records);

void writeFileWithFStream(StructWithStringSeq& records)
{
	cout << "write file begin..." << endl;

	ofstream outf(FILE_TITLE, ios::binary);
	if(outf)
	{
		for (int i = 0; i < records.size(); ++i)
		{
			records[i].writeStructToFile(outf);
		}
	}

	cout << "write file end..." << endl;
}

void readFileWithFStream()
{
	cout << "read file begin..." << endl;

	ifstream inf(FILE_TITLE, ios::binary);

	while(inf)
	{
		StructWithString record;
		if(record.readStructFromFile(inf))
		{
			cout << record << endl;
		}
	}
	
	cout << "read file end..." << endl;
}

int main()
{
	StructWithStringSeq records;
	initStrRecords(records);

	writeFileWithFStream(records);

	readFileWithFStream();

	return 0;
}