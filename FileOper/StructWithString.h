#ifndef STRUCTWITHSTRING_H
#define STRUCTWITHSTRING_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct StructWithString
{
	int i;
	string en_str;		// 英文字符串
	string ch_str;		// 中文字符串
	double d;

	// 将结构体写入文件
	bool writeStructToFile(FILE* outf);

	// 从文件中读取结构体
	bool readStructFromFile(ifstream& inf);

	// 从文件中读取结构体
	bool readStructFromFile(FILE* inf);

	// 将结构体写入文件
	bool writeStructToFile(ofstream& outf);


	friend ostream& operator<<(ostream& out, const StructWithString& record);
};
typedef vector<StructWithString> StructWithStringSeq;

#endif