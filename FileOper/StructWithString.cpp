
#include "StructWithString.h"

#define LIST_SIZE	10

// ��stringд���ļ�
void writeStrToFile(FILE* outf, const string& str)
{
	int len = str.size() + 1;
	fwrite(&len, sizeof(int), 1, outf);
	fwrite(str.c_str(), len, 1, outf);
}

// ��stringд���ļ�
void writeStrToFile(ofstream& outf, const string& str)
{
	int len = str.size() + 1;
	outf.write((char*)&len, sizeof(int));
	outf.write(str.c_str(), len);
}

// ���ļ��ж�ȡstring
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

// ���ļ��ж�ȡstring
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
		record.ch_str = "����";
		record.d = record.i * 2.0;

		records.push_back(record);
	}
}

// ���ṹ��д���ļ�
bool StructWithString::writeStructToFile( FILE* outf )
{
	fwrite(&i, sizeof(i), 1, outf);	
	writeStrToFile(outf, en_str);
	writeStrToFile(outf, ch_str);
	fwrite(&d, sizeof(d), 1, outf);
	return true;
}

// ���ṹ��д���ļ�
bool StructWithString::writeStructToFile( ofstream& outf )
{
	outf.write((char*)&i, sizeof(i));
	writeStrToFile(outf, en_str);
	writeStrToFile(outf, ch_str);
	outf.write((char*)&d, sizeof(d));
	return true;
}

// ���ļ��ж�ȡ�ṹ��
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

// ���ļ��ж�ȡ�ṹ��
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
