/*!
 * \file typeCastUtility.h
 * \date 2018/07/04 16:16
 *
 * \author Masf
 *
 * \brief 
 *
 * TODO: ����֧�ֻ�������������string����֮����໥ת��
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
	* ������T��ֵת��Ϊstring
	*/
	template<class T>
	string stringFromValue(T value);
	
	/*
	* ��stringת��Ϊ����T��ֵ
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
