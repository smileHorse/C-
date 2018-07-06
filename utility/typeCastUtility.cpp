
#include "typeCastUtility.h"

string TypeCastUtility::stringFromInt(int value)
{
	return stringFromValue(value);
}

string TypeCastUtility::stringFromFloat(float value)
{
	return stringFromValue(value);
}

string TypeCastUtility::stringFromLong(long value)
{
	return stringFromValue(value);
}

string TypeCastUtility::stringFromLLong(long long value)
{
	return stringFromValue(value);
}

string TypeCastUtility::stringFromDouble(double value)
{
	return stringFromValue(value);
}

string TypeCastUtility::stringFromBool(bool value)
{
	return stringFromValue(value ? 1 : 0);
}

int TypeCastUtility::stringToInt(const string& str)
{
	return atoi(str.c_str());
}

long TypeCastUtility::stringToLong(const string& str)
{
	return atol(str.c_str());
}

long long TypeCastUtility::stringToLLong(const string& str)
{
	return atoll(str.c_str());
}

float TypeCastUtility::stringToFloat(const string& str)
{
	return atof(str.c_str());
}

double TypeCastUtility::stringToDouble(const string& str)
{
	return atof(str.c_str());
}

bool TypeCastUtility::stringToBool(const string& str)
{
	return true;
}
