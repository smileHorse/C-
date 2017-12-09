
// 使用FILE操作带string的结构体的二进制文件读写
#include <iostream>

#include "StructWithString.h"

using namespace std;

#define FILE_TITLE	"struct_FILE.msg"

extern void initStrRecords(StructWithStringSeq& records);

void writeFileWithFile(StructWithStringSeq& records)
{
	cout << "write file begin..." << endl;

	FILE* outf = fopen(FILE_TITLE, "w+b");
	if (outf)
	{
		for (int i = 0; i < records.size(); ++i)
		{
			records[i].writeStructToFile(outf);
		}

		fclose(outf);
	}

	cout << "write file end..." << endl;
}

void readFileWithFile()
{
	cout << "read file begin..." << endl;

	FILE* inf = fopen(FILE_TITLE, "r+b");
	if (inf)
	{
		StructWithString record;
		while(!feof(inf))
		{
			if(record.readStructFromFile(inf))
			{
				cout << record << endl;
			}
		}

		fclose(inf);
	}

	cout << "read file end..." << endl;
}

int main7()
{
	StructWithStringSeq records;
	initStrRecords(records);

	writeFileWithFile(records);

	readFileWithFile();

	return 0;
}