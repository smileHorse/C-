
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FILE_TITLE	"test_records.msg"
#define LIST_SIZE	1

struct StrRecord
{
	int i;
	string str1;
	string str2;
	double d;

	bool writeToFile(FILE* outf);
	bool readFromFile(FILE* inf);

	friend ostream& operator<<(ostream& out, const StrRecord& record);
};

bool StrRecord::writeToFile( FILE* outf )
{
	char terminator = 0;
	fwrite(&i, sizeof(i), 1, outf);
	
	int len = str1.size() + 1;
	fwrite(&len, sizeof(int), 1, outf);
	fwrite(str1.c_str(), len, 1, outf);

	len = str2.size() + 1;
	fwrite(&len, sizeof(int), 1, outf);
	fwrite(str2.c_str(), len, 1, outf);

	fwrite(&d, sizeof(d), 1, outf);
	return true;
}

bool StrRecord::readFromFile( FILE* inf )
{
	int nItems = fread(&i, sizeof(i), 1, inf);
	if (nItems <= 0)
	{
		return true;
	}

	int len;
	fread(&len, sizeof(int), 1, inf);
	char* buf = new char[len];
	fread(buf, sizeof(char), len, inf);
	str1 = buf;

	fread(&len, sizeof(int), 1, inf);
	buf = new char[len];
	fread(buf, sizeof(char), len, inf);
	str2 = buf;

	fread(&d, sizeof(d), 1, inf);
	return true;
}

typedef vector<StrRecord> StrRecordSeq;

ostream& operator<<(ostream& out, const StrRecord& record )
{
	out << "i: " << record.i << ",\t";
	out << "str1: " << record.str1 << ",\t";
	out << "str2: " << record.str2 << ",\t";
	out << "d: " << record.d << ",\t";
	return out;
}

void initStrRecords(StrRecordSeq& records)
{
	for (int i = 0; i < LIST_SIZE; ++i)
	{
		StrRecord record;
		record.i = i + 1;
		record.str1 = "test1";
		record.str2 = "test2";
		record.d = record.i * 2.0;

		records.push_back(record);
	}
}

void writeFileWithFile(StrRecordSeq& records)
{
	cout << "write file begin..." << endl;

	try
	{
		FILE* outf = fopen(FILE_TITLE, "w+b");
		if (outf)
		{
			for (int i = 0; i < records.size(); ++i)
			{
				records[i].writeToFile(outf);
			}

			fclose(outf);
		}
	}
	catch(const exception& ex)
	{
		cout << "writeFile() exception: " << ex.what() << endl;
	}

	cout << "write file end..." << endl;
}

void readFileWithFile()
{
	cout << "read file begin..." << endl;

	try
	{
		FILE* inf = fopen(FILE_TITLE, "r+b");
		if (inf)
		{
			StrRecord record;
			while(!feof(inf))
			{
				record.readFromFile(inf);
				cout << record << endl;
			}

			fclose(inf);
		}
	}
	catch(const exception& ex)
	{
		cout << "readFile() exception: " << ex.what() << endl;
	}

	cout << "read file end..." << endl;
}

int main()
{
	StrRecordSeq records;
	initStrRecords(records);

	writeFileWithFile(records);

	readFileWithFile();

	return 0;
}