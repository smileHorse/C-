
#include <QtCore/QCoreApplication>

#include "WarningFileOper.h"

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

	return a.exec();
}
