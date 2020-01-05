/*!
 * \file typeCastUtility.h
 * \date 2018/07/04 16:16
 *
 * \author Masf
 *
 * \brief 
 *
 * TODO: 用于支持基础数据类型与string类型之间的相互转换
 *
 * \note
*/
#ifndef TYPECASTUTILITY_H
#define TYPECASTUTILITY_H

#include <sstream>
#include <string>

#include "fmt/core.h"


using std::string;
using std::stringstream;

class TypeCastUtility
{
public:
	string stringFromInt(int value);
	string stringFromFloat(float value);
	string stringFromLong(long value);
	string stringFromLLong(long long value);
	string stringFromDouble(double value);
	string stringFromBool(bool value);

	template<typename... Args>
	string formatString(const char* _format, const Args& ... args);

	int stringToInt(const string& str);
	long stringToLong(const string& str);
	long long stringToLLong(const string& str);
	float stringToFloat(const string& str);
	double stringToDouble(const string& str);
	bool stringToBool(const string& str);

private:
	/*
	* 将类型T的值转换为string
	*/
	template<class T>
	string stringFromValue(T value);
	
	/*
	* 将string转换为类型T的值
	*/
	template<class T>
	T stringToValue(const string& str);
	
};

template<typename... Args>
string TypeCastUtility::formatString(const char* _format, const Args& ... args)
{
	return fmt::format(_format, args...);
}

template<class T>
string TypeCastUtility::stringFromValue(T value)
{
	//stringstream stream;
	//stream << value;
	//return stream.str();

	return fmt::format("{}", value);
}

template<class T>
T TypeCastUtility::stringToValue(const string& str)
{
	stringstream stream(str);
	T value;
	stream >> value;
	return value;
}

#endif
