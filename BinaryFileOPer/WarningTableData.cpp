/********************************************************************
	created:	2017/11/14
	created:	14:11:2017   10:09
	filename: 	D:\KH-8100T\project\src\datasvr\opt\warningI\WarningTableData.cpp
	file path:	D:\KH-8100T\project\src\datasvr\opt\warningI
	file base:	WarningTableData
	file ext:	h
	author:		Masf
	
	purpose:	告警表数据类型
*********************************************************************/

#include "WarningTableData.h"

// 将标准string转换为QString
QString CAlarmTableDataImpl::convertStdStrToQStr( const string& str )
{
	return QString().fromStdString(str); 
}

// 将标准string转换为double
double CAlarmTableDataImpl::convertStdStrToDouble( const string& str )
{
	return QString().fromStdString(str).toDouble();
}

// 将标准string转换为int
int CAlarmTableDataImpl::convertStdStrToInt( const string& str )
{
	return QString().fromStdString(str).toInt();
}

// 将int转换为QString
QString CAlarmTableDataImpl::convertIntToQStr( int value )
{
	return QString("%1").arg(value);
}

// 将QString写入文件
void CAlarmTableDataImpl::writeQStrToFile(FILE* outf, const QString& str )
{
	int len = str.length() + 1;
	fwrite(&len, sizeof(int), 1, outf);
	fwrite(str.data(), len, 1, outf);
}

// 从文件中读取QString
void CAlarmTableDataImpl::readQStrFromFile(FILE* inf, QString& str )
{
	int len;
	fread(&len, sizeof(int), 1, inf);
	char ch[BUFSIZ];
	if (len > BUFSIZ)
	{
		char* tmpCh = new char[len];
		fread(tmpCh, len, 1, inf);
		str = tmpCh;
		delete [] tmpCh;
	}
	else
	{
		fread(ch, len, 1, inf);
		str = ch;
	}
}

/************************************************************************/
/*告警表通用数据				                                        */
/************************************************************************/

CAlarmTableData::CAlarmTableData()
	: id(""), datet(""), warnSource(""), warnLevel("")
{}

void CAlarmTableData::transformToVector( QVector<QVariant>& values ) const
{
	values.clear();
	values << id << datet;
	transformToVectorImpl(values);
	values << warnSource << warnLevel;
}

void CAlarmTableData::transformToQString( QString& str ) const
{
	QVector<QVariant> values;
	transformToVector(values);
	QStringList fields;
	getDataField(fields);
	for (int i = 0; i < values.size(); ++i)
	{
		str += (i == 0 ? "" : ", ");
		str += fields.at(i) + ": " + values.at(i).toString();
	}
}

void CAlarmTableData::getDataField( QStringList& strList ) const
{
	strList.clear();
	strList << "id" << "datet";
	getDataFieldImpl(strList);
	strList << "warnSource" << "warnLevel";
}

bool CAlarmTableData::writeToBinaryFile( FILE* outf )
{
	int type = getAlarmTableDataType();
	fwrite(&type, sizeof(int), 1, outf);

	m_impl.writeQStrToFile(outf, id);
	m_impl.writeQStrToFile(outf, datet);

	writeToBinaryFileImpl(outf);	

	m_impl.writeQStrToFile(outf, warnSource);
	m_impl.writeQStrToFile(outf, warnLevel);

	return true;
}

bool CAlarmTableData::readFromBinaryFile( FILE* inf )
{
	m_impl.readQStrFromFile(inf, id);
	m_impl.readQStrFromFile(inf, datet);

	readFromBinaryFileImpl(inf);

	m_impl.readQStrFromFile(inf, warnSource);
	m_impl.readQStrFromFile(inf, warnLevel);
	
	return true;
}

/************************************************************************/
/*遥测越限表	t_alarm_limittb                                         */
/************************************************************************/
CAlarmLimitTableData::CAlarmLimitTableData()
	: station(""), equipName(""), line(""), dataName(""), state(""),
	limitVal(0.0), currVal(0.0), sms_flag("")
{}

void CAlarmLimitTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << station << equipName << line << dataName << state << limitVal 
		   << currVal << sms_flag;
}

void CAlarmLimitTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "station" << "equipName" << "line" << "dataName" << "state" << "limitVal" 
		<< "currVal" << "sms_flag";
}

int CAlarmLimitTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Limit;
}

void CAlarmLimitTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, line);
	m_impl.writeQStrToFile(outf, dataName);
	m_impl.writeQStrToFile(outf, state);
	fwrite(&limitVal, sizeof(double), 1, outf);
	fwrite(&currVal, sizeof(double), 1, outf);
	m_impl.writeQStrToFile(outf, sms_flag);
}

void CAlarmLimitTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, line);
	m_impl.readQStrFromFile(inf, dataName);
	m_impl.readQStrFromFile(inf, state);
	fread(&limitVal, sizeof(double), 1, inf);
	fread(&currVal, sizeof(double), 1, inf);
	m_impl.readQStrFromFile(inf, sms_flag);
}

/************************************************************************/
/*SOE表	t_alarm_soetb                                         */
/************************************************************************/
CAlarmSoeTableData::CAlarmSoeTableData()
	: station(""), equipName(""), line(""), dataName(""), type(""), state(0), sms_flag("")
{}

void CAlarmSoeTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << station << equipName << line << dataName << type << state << sms_flag;
}

void CAlarmSoeTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "station" << "equipName" << "line" << "dataName" << "type" 
		<< "state" << "sms_flag";
}

int CAlarmSoeTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Soe;
}

void CAlarmSoeTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, line);
	m_impl.writeQStrToFile(outf, dataName);
	m_impl.writeQStrToFile(outf, type);
	fwrite(&state, sizeof(int), 1, outf);
	m_impl.writeQStrToFile(outf, sms_flag);
}

void CAlarmSoeTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, line);
	m_impl.readQStrFromFile(inf, dataName);
	m_impl.readQStrFromFile(inf, type);
	fread(&state, sizeof(int), 1, inf);
	m_impl.readQStrFromFile(inf, sms_flag);
}

/************************************************************************/
/*遥信变位表	t_alarm_yxtb	                                        */
/************************************************************************/
CAlarmYxTableData::CAlarmYxTableData()
	: station(""), equipName(""), line(""), dataName(""), type(""), state(0)
{}

void CAlarmYxTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << station << equipName << line << dataName << type << state;
}

void CAlarmYxTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "station" << "equipName" << "line" << "dataName" << "type" 
		<< "state";
}

int CAlarmYxTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Yx;
}

void CAlarmYxTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, line);
	m_impl.writeQStrToFile(outf, dataName);
	m_impl.writeQStrToFile(outf, type);
	fwrite(&state, sizeof(int), 1, outf);
}

void CAlarmYxTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, line);
	m_impl.readQStrFromFile(inf, dataName);
	m_impl.readQStrFromFile(inf, type);
	fread(&state, sizeof(int), 1, inf);
}

/************************************************************************/
/*操作事项表	t_alarm_opertb	                                        */
/************************************************************************/
CAlarmOperTableData::CAlarmOperTableData()
	: type(0), station(""), equipName(""), line(""), dataName(""), 
	host(""), oper(""), content("")
{}

void CAlarmOperTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << type << station << equipName << line << dataName << host << oper << content;
}

void CAlarmOperTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "type" << "station" << "equipName" << "line" << "dataName" << "host" 
		<< "oper" << "content";
}

int CAlarmOperTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Oper;
}

void CAlarmOperTableData::writeToBinaryFileImpl( FILE* outf )
{
	fwrite(&type, sizeof(int), 1, outf);
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, line);
	m_impl.writeQStrToFile(outf, dataName);
	m_impl.writeQStrToFile(outf, host);
	m_impl.writeQStrToFile(outf, oper);
	m_impl.writeQStrToFile(outf, content);
}

void CAlarmOperTableData::readFromBinaryFileImpl( FILE* inf )
{
	fread(&type, sizeof(int), 1, inf);
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, line);
	m_impl.readQStrFromFile(inf, dataName);
	m_impl.readQStrFromFile(inf, host);
	m_impl.readQStrFromFile(inf, oper);
	m_impl.readQStrFromFile(inf, content);
}

/************************************************************************/
/*系统事项表	t_alarm_syseventtb	                                        */
/************************************************************************/
CAlarmSysEventTableData::CAlarmSysEventTableData()
	: type(""), host(""), oper(""), content("")
{}

void CAlarmSysEventTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << type << host << oper << content;
}

void CAlarmSysEventTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "type" << "host" << "oper" << "content";
}

int CAlarmSysEventTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_SysEvent;
}

void CAlarmSysEventTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, type);
	m_impl.writeQStrToFile(outf, host);
	m_impl.writeQStrToFile(outf, oper);
	m_impl.writeQStrToFile(outf, content);
}

void CAlarmSysEventTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, type);
	m_impl.readQStrFromFile(inf, host);
	m_impl.readQStrFromFile(inf, oper);
	m_impl.readQStrFromFile(inf, content);
}

/************************************************************************/
/*保护事项表	t_alarm_relaytb	                                        */
/************************************************************************/
CAlarmRelayTableData::CAlarmRelayTableData()
	: deviceId(0), station(""), equipName(""), line(""), dataName(""), content(""),
	manufact(""), lineType(""), proTypeNo(0), proTypeName(""), isEvent(""), modulus(0.0),
	units("")
{}

void CAlarmRelayTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << deviceId << station << equipName << line << dataName << content 
		   << manufact << lineType << proTypeNo << proTypeName << isEvent 
		   << modulus << units;
}

void CAlarmRelayTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "deviceId" << "station" << "equipName" << "line" << "dataName" << "content" 
		<< "manufact" << "lineType" << "proTypeNo" << "proTypeName" << "isEvent" 
		<< "modulus" << "units";
};

int CAlarmRelayTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Relay;
}

void CAlarmRelayTableData::writeToBinaryFileImpl( FILE* outf )
{
	fwrite(&deviceId, sizeof(int), 1, outf);
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, line);
	m_impl.writeQStrToFile(outf, dataName);
	m_impl.writeQStrToFile(outf, content);
	m_impl.writeQStrToFile(outf, manufact);
	m_impl.writeQStrToFile(outf, lineType);
	fwrite(&proTypeNo, sizeof(int), 1, outf);
	m_impl.writeQStrToFile(outf, proTypeName);
	m_impl.writeQStrToFile(outf, isEvent);
	fwrite(&modulus, sizeof(int), 1, outf);
	m_impl.writeQStrToFile(outf, units);
}

void CAlarmRelayTableData::readFromBinaryFileImpl( FILE* inf )
{
	fread(&deviceId, sizeof(int), 1, inf);
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, line);
	m_impl.readQStrFromFile(inf, dataName);
	m_impl.readQStrFromFile(inf, content);
	m_impl.readQStrFromFile(inf, manufact);
	m_impl.readQStrFromFile(inf, lineType);
	fread(&proTypeNo, sizeof(int), 1, inf);
	m_impl.readQStrFromFile(inf, proTypeName);
	m_impl.readQStrFromFile(inf, isEvent);
	fread(&modulus, sizeof(int), 1, inf);
	m_impl.readQStrFromFile(inf, units);
}

/************************************************************************/
/*单元状态表	t_alarm_rtutb                                         */
/************************************************************************/
CAlarmRtuTableData::CAlarmRtuTableData()
	: deviceId(0), station(""), equipName(""), line(""), state("")
{}

void CAlarmRtuTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << deviceId << station << equipName << line << state;
}

void CAlarmRtuTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "deviceId" << "station" << "equipName" << "line" << "state";
}

int CAlarmRtuTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Rtu;
}

void CAlarmRtuTableData::writeToBinaryFileImpl( FILE* outf )
{
	fwrite(&deviceId, sizeof(int), 1, outf);
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, line);
	m_impl.writeQStrToFile(outf, state);
}

void CAlarmRtuTableData::readFromBinaryFileImpl( FILE* inf )
{
	fread(&deviceId, sizeof(int), 1, inf);
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, line);
	m_impl.readQStrFromFile(inf, state);
}

/************************************************************************/
/*图形操作表	t_alarm_graphtb                                         */
/************************************************************************/
CAlarmGraphTableData::CAlarmGraphTableData()
	: graphId(""), graphName(""), graphType(""), state("")
{}

void CAlarmGraphTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << graphId << graphName << graphType << state;
}

void CAlarmGraphTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "graphId" << "graphName" << "graphType" << "state";
}

int CAlarmGraphTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Graph;
}

void CAlarmGraphTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, graphId);
	m_impl.writeQStrToFile(outf, graphName);
	m_impl.writeQStrToFile(outf, graphType);
	m_impl.writeQStrToFile(outf, state);
}

void CAlarmGraphTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, graphId);
	m_impl.readQStrFromFile(inf, graphName);
	m_impl.readQStrFromFile(inf, graphType);
	m_impl.readQStrFromFile(inf, state);
}

/************************************************************************/
/*Fa表	t_alarm_fatb                                         */
/************************************************************************/
CAlarmFaTableData::CAlarmFaTableData()
	: faultId(""), content("")
{}

void CAlarmFaTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << faultId << content;
}

void CAlarmFaTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "faultId" << "content";
}

int CAlarmFaTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Fa;
}

void CAlarmFaTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, faultId);
	m_impl.writeQStrToFile(outf, content);
}

void CAlarmFaTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, faultId);
	m_impl.readQStrFromFile(inf, content);
}

/************************************************************************/
/*故障事项表	t_alarm_faulttb                                         */
/************************************************************************/
CAlarmFaultTableData::CAlarmFaultTableData()
	: line(""), station(""), equipName(""), faultType(""), selLineReliability(0), iValues(""), 
	factorJD(""), sms_flag("")
{}

void CAlarmFaultTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << line << station << equipName << faultType << selLineReliability << iValues 
		   << factorJD << sms_flag;
}

void CAlarmFaultTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "line" << "station" << "equipName" << "faultType" << "selLineReliability" << "iValues" 
			<< "factorJD" << "sms_flag";
}

int CAlarmFaultTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Fault;
}

void CAlarmFaultTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, line);
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, faultType);
	fwrite(&selLineReliability, sizeof(int), 1, outf);
	m_impl.writeQStrToFile(outf, iValues);
	m_impl.writeQStrToFile(outf, factorJD);
	m_impl.writeQStrToFile(outf, sms_flag);
}

void CAlarmFaultTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, line);
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, equipName);
	fread(&selLineReliability, sizeof(int), 1, inf);
	m_impl.readQStrFromFile(inf, iValues);
	m_impl.readQStrFromFile(inf, factorJD);
	m_impl.readQStrFromFile(inf, sms_flag);
}

/************************************************************************/
/*录波事项表	t_alarm_rfwtb                                         */
/************************************************************************/
CAlarmRfwTableData::CAlarmRfwTableData()
	: station(""), equipName(""), line(""), faultType(-1), type(-1), reason(-1)
{
}

void CAlarmRfwTableData::transformToVectorImpl( QVector<QVariant>& values ) const
{
	values << station << equipName << line << faultType << type << reason;
}

void CAlarmRfwTableData::getDataFieldImpl( QStringList& strList ) const
{
	strList << "station" << "equipName" << "line" << "faultType" << "type" << "reason";
}

int CAlarmRfwTableData::getAlarmTableDataType() const
{
	return CWarningDataManager::Table_Alarm_Rfw;
}

void CAlarmRfwTableData::writeToBinaryFileImpl( FILE* outf )
{
	m_impl.writeQStrToFile(outf, station);
	m_impl.writeQStrToFile(outf, equipName);
	m_impl.writeQStrToFile(outf, line);
	fwrite(&faultType, sizeof(int), 1, outf);
	fwrite(&type, sizeof(int), 1, outf);
	fwrite(&reason, sizeof(int), 1, outf);
}

void CAlarmRfwTableData::readFromBinaryFileImpl( FILE* inf )
{
	m_impl.readQStrFromFile(inf, station);
	m_impl.readQStrFromFile(inf, equipName);
	m_impl.readQStrFromFile(inf, line);
	fread(&faultType, sizeof(int), 1, inf);
	fread(&type, sizeof(int), 1, inf);
	fread(&reason, sizeof(int), 1, inf);
}
