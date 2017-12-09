
#include "StructWithString.h"

#define LIST_SIZE	10

// 将string写入文件
void writeStrToFile(FILE* outf, const string& str)
{
	int len = str.size() + 1;
	fwrite(&len, sizeof(int), 1, outf);
	fwrite(str.c_str(), len, 1, outf);
}

// 将string写入文件
void writeStrToFile(ofstream& outf, const string& str)
{
	int len = str.size() + 1;
	outf.write((char*)&len, sizeof(int));
	outf.write(str.c_str(), len);
}

// 从文件中读取string
void readStrFromFile(FILE* inf, string& str)
{
	int len;
	char buf[BUFSIZ] = {0};
	fread(&len, sizeof(int), 1, inf);
	if (len < BUFSIZ)
	{
		fread(buf, sizeof(char), len, inf);
		str = buf;
	}
	else
	{
		char* ch = new char[len];
		fread(ch, sizeof(char), len ,inf);
		str = ch;
	}
}

// 从文件中读取string
void readStrFromFile(ifstream& inf, string& str)
{
	int len;
	char buf[BUFSIZ] = {0};
	inf.read((char*)&len, sizeof(int));
	if (len < BUFSIZ)
	{
		inf.read(buf, len);
		str = buf;
	}
	else
	{
		char* ch = new char[len];
		inf.read(buf, len);
		str = ch;
	}
}

ostream& operator<<(ostream& out, const StructWithString& record )
{
	out << "i: " << record.i << ",\t";
	out << "en_str: " << record.en_str << ",\t";
	out << "ch_str: " << record.ch_str << ",\t";
	out << "d: " << record.d << ",\t";
	return out;
}

void initStrRecords(StructWithStringSeq& records)
{
	for (int i = 0; i < LIST_SIZE; ++i)
	{
		StructWithString record;
		record.i = i + 1;
		record.en_str = "english";
		record.ch_str = "中文";
		record.d = record.i * 2.0;

		records.push_back(record);
	}
}

// 将结构体写入文件
bool StructWithString::writeStructToFile( FILE* outf )
{
	fwrite(&i, sizeof(i), 1, outf);	
	writeStrToFile(outf, en_str);
	writeStrToFile(outf, ch_str);
	fwrite(&d, sizeof(d), 1, outf);
	return true;
}

// 将结构体写入文件
bool StructWithString::writeStructToFile( ofstream& outf )
{
	outf.write((char*)&i, sizeof(i));
	writeStrToFile(outf, en_str);
	writeStrToFile(outf, ch_str);
	outf.write((char*)&d, sizeof(d));
	return true;
}

// 从文件中读取结构体
bool StructWithString::readStructFromFile( FILE* inf )
{
	int nItems = fread(&i, sizeof(i), 1, inf);
	if (nItems <= 0)
	{
		return false;
	}

	readStrFromFile(inf, en_str);
	readStrFromFile(inf, ch_str);
	fread(&d, sizeof(d), 1, inf);
	return true;
}

// 从文件中读取结构体
bool StructWithString::readStructFromFile( ifstream& inf )
{
	inf.read((char*)&i, sizeof(i));
	if (!inf)
	{
		return false;
	}
	readStrFromFile(inf, en_str);
	readStrFromFile(inf, ch_str);
	inf.read((char*)&d, sizeof(d));
	return true;
}
