#ifndef WARNINGFILEOPER_H
#define WARNINGFILEOPER_H

#include <QtCore/QtCore>

class CAlarmTableData;
typedef QVector<CAlarmTableData>	CAlarmTableDataSeq;
typedef QSharedPointer<CAlarmTableData>	CAlarmTableDataPtr;
typedef QVector< CAlarmTableDataPtr >	CAlarmTableDataPtrSeq;

class WarningFileOper
{
public:
	// д���ļ�
	bool writeToBinaryFile();

	// ��ȡ�ļ�
	bool readFromBinaryFile(CAlarmTableDataPtrSeq& tableDatas);

	// �����ȡ��������
	void outputWarningMsg(const CAlarmTableDataPtrSeq& tableDatas);

private:
	// ��ʼ����������
	void initAlarmTableDatas(CAlarmTableDataPtrSeq& tableDatas);
};

#endif