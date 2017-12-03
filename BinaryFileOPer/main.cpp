
#include "WarningFileOper.h"

#include <QtCore/QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


#define FILE_TITLE1	"chinese.msg"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	WarningFileOper fileOper;
	// д���ļ�
	fileOper.writeToBinaryFile();

	// ��ȡ�ļ�
	CAlarmTableDataPtrSeq tableDatas;
	fileOper.readFromBinaryFile(tableDatas);

	// �����ȡ���ļ�����
	fileOper.outputWarningMsg(tableDatas);

	//FILE* outf = fopen(FILE_TITLE1, "w+b");
	//if (outf)
	//{
	//	//QString str = QStringLiteral("����");
	//	QString str = QStringLiteral("abc");
	//	QByteArray array = str.toLocal8Bit();
	//	int len = array.size() + 1;
	//	fwrite(&len, sizeof(int), 1, outf);
	//	fwrite(array.data(), len, 1, outf);

	//	qDebug() << QStringLiteral("д���ļ�:") << str;
	//	fclose(outf);
	//}

	//FILE* inf = fopen(FILE_TITLE1, "r+b");
	//if (inf)
	//{
	//	int len;
	//	fread(&len, sizeof(int), 1, inf);
	//	char ch[BUFSIZ];
	//	fread(ch, len, 1, inf);
	//	QByteArray array(ch);
	//	QString str = QString::fromLocal8Bit(array);

	//	qDebug() << QStringLiteral("�ļ���ȡ:") << str;
	//	fclose(inf);		
	//}

	//FILE* outf = fopen(FILE_TITLE1, "w+b");
	//if (outf)
	//{
	//	string str = "����";
	//	//string str = "abc";
	//	int len = str.size() + 1;
	//	fwrite(&len, sizeof(int), 1, outf);
	//	fwrite(str.c_str(), len, 1, outf);

	//	cerr << "д���ļ���" << str << endl;;
	//	fclose(outf);
	//}

	//FILE* inf = fopen(FILE_TITLE1, "r+b");
	//if (inf)
	//{
	//	int len;
	//	fread(&len, sizeof(int), 1, inf);
	//	char ch[BUFSIZ];
	//	fread(ch, len, 1, inf);
	//	string str = ch;

	//	cerr << "�ļ���ȡ: " << str << endl;;
	//	fclose(inf);		
	//}

	return a.exec();
}
