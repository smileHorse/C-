
#include "WarningFileOper.h"
#include "WarningTableData.h"

#include <iostream>

using namespace std;

#define FILE_TITLE	"WarningMsg.msg"
#define DATA_COUNT	1

// 写入文件
bool WarningFileOper::writeToBinaryFile()
{
	CAlarmTableDataPtrSeq tableDatas;
	initAlarmTableDatas(tableDatas);

	FILE* outf = NULL;
	if ((outf = fopen(FILE_TITLE, "w+b")) == NULL)
	{
		cerr << "writeToBinaryFile: 打开告警文件出错..." << endl;
		return false;
	}

	for (int i = 0; i < tableDatas.size(); ++i)
	{
		tableDatas[i]->writeToBinaryFile(outf);
	}

	fclose(outf);

	return true;
}

// 读取文件
bool WarningFileOper::readFromBinaryFile(CAlarmTableDataPtrSeq& tableDatas)
{
	FILE* inf = NULL;
	if ((inf = fopen(FILE_TITLE, "r+b")) == NULL)
	{
		cerr << "readFromBinaryFile: 打开告警文件出错..." << endl;
		return false;
	}

	while(!feof(inf))
	{
		int type;
		int nItems = fread(&type, sizeof(int), 1, inf);
		if (nItems <= 0)
		{
			break;
		}

		switch(type)
		{
		case CWarningDataManager::Table_Alarm_Limit:
			{
				QSharedPointer<CAlarmLimitTableData> data = QSharedPointer<CAlarmLimitTableData>::create();
				data->readFromBinaryFile(inf);

				tableDatas.push_back(data);
				break;
			}
		default:
			break;
		}
	}

	return true;
}

// 输出读取到的数据
void WarningFileOper::outputWarningMsg( const CAlarmTableDataPtrSeq& tableDatas )
{
	QString str;
	for (int i = 0; i < tableDatas.size(); ++i)
	{
		str.clear();
		tableDatas[i]->transformToQString(str);
		qDebug() << str << endl;
	}
}

// 初始化测试数据
void WarningFileOper::initAlarmTableDatas( CAlarmTableDataPtrSeq& tableDatas )
{
	QStringList randomStrs;
	randomStrs << QStringLiteral("算法导论") << QStringLiteral("大话数据结构") << QStringLiteral("大话设计模式") << QStringLiteral("Unix私房菜")
			<< QStringLiteral("Python核心编程") << QStringLiteral("Python CookBook") << QStringLiteral("JavaScript权威指南") 
			<< QStringLiteral("Java核心技术卷II") 	<< QStringLiteral("精通Qt4编程") << QStringLiteral("Linux基础学习");

	QStringList randomIds;
	randomIds << "34567895" << "16614564" << "464564454" << "78676+783" << "7463456345634" << "73743774537";

	QStringList randomDates;
	randomDates << "2017-11-23 10:04:40" <<  "2017-11-2 10:24:40" << "2017-11-14 7:04:40" << "2017-11-4 10:04:40" 
		<< "2017-11-6 10:04:40" << "2017-11-8 10:04:40" << "2017-11-9 10:04:40" << "2017-11-3 10:04:40" << "2017-11-5 10:04:40";

	// 初始化遥测越限数据
	for (int i = 0; i < DATA_COUNT; ++i)
	{
		QSharedPointer<CAlarmLimitTableData> data = QSharedPointer<CAlarmLimitTableData>::create();
		data->id = randomStrs.at(qrand() % randomStrs.size());
		data->datet = randomStrs.at(qrand() % randomStrs.size());
		data->station = randomStrs.at(qrand() % randomStrs.size());
		data->equipName = randomStrs.at(qrand() % randomStrs.size());
		data->line = randomStrs.at(qrand() % randomStrs.size());
		data->dataName = randomStrs.at(qrand() % randomStrs.size());
		data->state = randomStrs.at(qrand() % randomStrs.size());
		data->limitVal = 10;
		data->currVal = 20;
		data->sms_flag = randomStrs.at(qrand() % randomStrs.size());
		data->warnSource = randomStrs.at(qrand() % randomStrs.size());
		data->warnLevel = randomStrs.at(qrand() % randomStrs.size());

		tableDatas.push_back(data);
	}

}
