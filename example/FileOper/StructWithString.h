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
	string en_str;		// Ӣ���ַ���
	string ch_str;		// �����ַ���
	double d;

	// ���ṹ��д���ļ�
	bool writeStructToFile(FILE* outf);

	// ���ļ��ж�ȡ�ṹ��
	bool readStructFromFile(ifstream& inf);

	// ���ļ��ж�ȡ�ṹ��
	bool readStructFromFile(FILE* inf);

	// ���ṹ��д���ļ�
	bool writeStructToFile(ofstream& outf);


	friend ostream& operator<<(ostream& out, const StructWithString& record);
};
typedef vector<StructWithString> StructWithStringSeq;

#endif