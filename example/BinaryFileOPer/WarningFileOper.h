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
	// 写入文件
	bool writeToBinaryFile();

	// 读取文件
	bool readFromBinaryFile(CAlarmTableDataPtrSeq& tableDatas);

	// 输出读取到的数据
	void outputWarningMsg(const CAlarmTableDataPtrSeq& tableDatas);

private:
	// 初始化测试数据
	void initAlarmTableDatas(CAlarmTableDataPtrSeq& tableDatas);
};

#endif