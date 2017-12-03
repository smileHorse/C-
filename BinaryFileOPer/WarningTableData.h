/********************************************************************
	created:	2017/11/14
	created:	14:11:2017   10:09
	filename: 	D:\KH-8100T\project\src\datasvr\opt\warningI\WarningTableData.h
	file path:	D:\KH-8100T\project\src\datasvr\opt\warningI
	file base:	WarningTableData
	file ext:	h
	author:		Masf
	
	purpose:	告警表数据类型
*********************************************************************/

#ifndef WARNINGTABLEDATA_H
#define WARNINGTABLEDATA_H

#include <string>
#include <QtCore/QtCore>

using namespace std;

class CWarningDataManager
{
public:
	enum CheckedTables
	{
		Table_Alarm_Limit = 0,
		Table_Alarm_Soe,
		Table_Alarm_Yx,
		Table_Alarm_SysEvent,
		Table_Alarm_Oper,
		Table_Alarm_Relay,
		Table_Alarm_Rtu,
		Table_Alarm_Graph,
		Table_Alarm_Fa,
		Table_Alarm_Fault,
		Table_Alarm_Rfw,
		Table_Count
	};
};

class CAlarmTableDataImpl
{
public:
	
	// 将标准string转换为QString
	QString	convertStdStrToQStr(const string& str);
	
	// 将标准string转换为double
	double	convertStdStrToDouble(const string& str);
	
	// 将标准string转换为int
	int	convertStdStrToInt(const string& str);
	
	// 将int转换为QString
	QString	convertIntToQStr(int value);

	// 将QString写入文件
	void writeQStrToFile(FILE* outf, const QString& str);

	// 从文件中读取QString
	void readQStrFromFile(FILE* inf, QString& str);
};

// 告警表通用数据
class CAlarmTableData
{
public:
	CAlarmTableData();

	void transformToVector(QVector<QVariant>& values) const;
	
	virtual void transformToVectorImpl(QVector<QVariant>& values) const = 0;

	void transformToQString(QString& str) const;

	virtual void getDataField(QStringList& strList) const;

	virtual void getDataFieldImpl(QStringList& strList) const = 0;

	virtual	int getAlarmTableDataType() const = 0;

	virtual bool writeToBinaryFile(FILE* outf);
	virtual void writeToBinaryFileImpl(FILE* outf) = 0;

	virtual bool readFromBinaryFile(FILE* inf);
	virtual void readFromBinaryFileImpl(FILE* inf) = 0;
	
protected:
	CAlarmTableDataImpl	m_impl;

public:
	QString	id;
	QString	datet;
	QString	warnSource;
	QString	warnLevel;
};
typedef QVector<CAlarmTableData>	CAlarmTableDataSeq;
typedef QSharedPointer<CAlarmTableData>	CAlarmTableDataPtr;
typedef QVector< CAlarmTableDataPtr >	CAlarmTableDataPtrSeq;

// 遥测越限表数据
class CAlarmLimitTableData : public CAlarmTableData
{
public:
	CAlarmLimitTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);
public:
	QString	station;
	QString	equipName;
	QString	line;
	QString	dataName;
	QString	state;
	double	limitVal;
	double	currVal;
	QString	sms_flag;
};
typedef QVector<CAlarmLimitTableData>	CAlarmLimitTableDataSeq;

// SOE表数据
class CAlarmSoeTableData : public CAlarmTableData
{
public:
	CAlarmSoeTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);
	
public:
	QString	station;
	QString	equipName;
	QString	line;
	QString	dataName;
	QString type;
	int		state;
	QString	sms_flag;
};
typedef QVector<CAlarmSoeTableData>	CAlarmSoeTableDataSeq;

// 遥信变位表数据
class CAlarmYxTableData : public CAlarmTableData
{
public:
	CAlarmYxTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);
	
public:
	QString	station;
	QString	equipName;
	QString	line;
	QString	dataName;
	QString type;
	int		state;
};
typedef QVector<CAlarmYxTableData>	CAlarmYxTableDataSeq;

// 操作事项表数据
class CAlarmOperTableData : public CAlarmTableData
{
public:
	CAlarmOperTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	int		type;
	QString	station;
	QString	equipName;
	QString	line;
	QString	dataName;
	QString host;
	QString	oper;
	QString	content;
};
typedef QVector<CAlarmOperTableData>	CAlarmOperTableDataSeq;

// 系统事项表数据
class CAlarmSysEventTableData : public CAlarmTableData
{
public:
	CAlarmSysEventTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	QString	type;
	QString	host;
	QString	oper;
	QString	content;
};
typedef QVector<CAlarmSysEventTableData>	CAlarmSysEventTableDataSeq;

// 保护事项表数据
class CAlarmRelayTableData : public CAlarmTableData
{
public:
	CAlarmRelayTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	int		deviceId;
	QString	station;
	QString	equipName;
	QString	line;
	QString	dataName;
	QString	content;
	QString	manufact;
	QString	lineType;
	int		proTypeNo;
	QString	proTypeName;
	QString	isEvent;
	double	modulus;
	QString	units;
};
typedef QVector<CAlarmRelayTableData>	CAlarmRelayTableDataSeq;

// 单元状态表数据
class CAlarmRtuTableData : public CAlarmTableData
{
public:
	CAlarmRtuTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	int		deviceId;
	QString	station;
	QString	equipName;
	QString	line;
	QString	state;
};
typedef QVector<CAlarmRtuTableData>	CAlarmRtuTableDataSeq;

// 图形操作表数据
class CAlarmGraphTableData : public CAlarmTableData
{
public:
	CAlarmGraphTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	QString	graphId;
	QString	graphName;
	QString	graphType;
	QString	state;
};
typedef QVector<CAlarmGraphTableData>	CAlarmGraphTableDataSeq;

// 图形操作表数据
class CAlarmFaTableData : public CAlarmTableData
{
public:
	CAlarmFaTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	QString	faultId;
	QString	content;
};
typedef QVector<CAlarmFaTableData>	CAlarmFaTableDataSeq;

// 故障事项表数据
class CAlarmFaultTableData : public CAlarmTableData
{
public:
	CAlarmFaultTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	QString	line;
	QString	station;
	QString	equipName;
	QString	faultType;
	int		selLineReliability;
	QString	iValues;
	QString	factorJD;
	QString	sms_flag;
};
typedef QVector<CAlarmFaultTableData>	CAlarmFaultTableDataSeq;

// 录波事项表数据
class CAlarmRfwTableData : public CAlarmTableData
{
public:
	CAlarmRfwTableData();

	void transformToVectorImpl(QVector<QVariant>& values) const;

	virtual void getDataFieldImpl(QStringList& strList) const;

	virtual	int getAlarmTableDataType() const;

	virtual void writeToBinaryFileImpl(FILE* outf);

	virtual void readFromBinaryFileImpl(FILE* inf);

public:
	QString	station;
	QString	equipName;
	QString	line;
	int		faultType;
	int		type;
	int		reason;
};
typedef QVector<CAlarmRfwTableData>	CAlarmRfwTableDataSeq;

#endif