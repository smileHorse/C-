
#include <QtCore/QCoreApplication>

#include "WarningFileOper.h"

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

	return a.exec();
}
