
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
	// 写入文件
	fileOper.writeToBinaryFile();

	// 读取文件
	CAlarmTableDataPtrSeq tableDatas;
	fileOper.readFromBinaryFile(tableDatas);

	// 输出读取的文件内容
	fileOper.outputWarningMsg(tableDatas);

	//FILE* outf = fopen(FILE_TITLE1, "w+b");
	//if (outf)
	//{
	//	//QString str = QStringLiteral("中文");
	//	QString str = QStringLiteral("abc");
	//	QByteArray array = str.toLocal8Bit();
	//	int len = array.size() + 1;
	//	fwrite(&len, sizeof(int), 1, outf);
	//	fwrite(array.data(), len, 1, outf);

	//	qDebug() << QStringLiteral("写入文件:") << str;
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

	//	qDebug() << QStringLiteral("文件读取:") << str;
	//	fclose(inf);		
	//}

	//FILE* outf = fopen(FILE_TITLE1, "w+b");
	//if (outf)
	//{
	//	string str = "中文";
	//	//string str = "abc";
	//	int len = str.size() + 1;
	//	fwrite(&len, sizeof(int), 1, outf);
	//	fwrite(str.c_str(), len, 1, outf);

	//	cerr << "写入文件：" << str << endl;;
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

	//	cerr << "文件读取: " << str << endl;;
	//	fclose(inf);		
	//}

	return a.exec();
}
