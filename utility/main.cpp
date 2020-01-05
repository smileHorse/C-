
#include <iostream>
using std::cout;
using std::endl;

#include "typeCastUtility.h"


template<class T>
void output(const string str, const T& t)
{
	cout << str << "\t" << t << endl;
}

int main()
{
	TypeCastUtility typeCast;

	output("stringFromInt(-1)", typeCast.stringFromInt(-1));
	output("stringFromInt(0)", typeCast.stringFromInt(0));
	output("stringFromInt(1)", typeCast.stringFromInt(1));
	output("stringFromFloat(-1.5)", typeCast.stringFromFloat(-1.5));
	output("stringFromFloat(1.5)", typeCast.stringFromFloat(1.5));
	output("stringFromDouble(1.500006)", typeCast.stringFromDouble(1.500006));
	output("stringFromDouble(2e-7)", typeCast.stringFromDouble(2e-7));
	
	int iValue = typeCast.stringToInt("-1");
	output("stringToInt(-1)", iValue);
	iValue = typeCast.stringToInt("0");
	output("stringToInt(0)", iValue);
	iValue = typeCast.stringToInt("1");
	output("stringToInt(1)", iValue);

	float fValue = typeCast.stringToFloat("-1.5");
	output("stringToFloat(-1.5)", fValue);
	fValue = typeCast.stringToFloat("1.5");
	output("stringToFloat(1.5)", fValue);
	double dValue = typeCast.stringToDouble("1.500006");
	output("stringToDouble(1.500006)", dValue);
	dValue = typeCast.stringToDouble("2e-7");
	output("stringToDouble(2e-7)", dValue);

	dValue = typeCast.stringToDouble("aaa");
	output("stringToValue('aaa')", dValue);

	output("stringFromDouble(infinity)", typeCast.stringFromDouble(std::numeric_limits<double>::infinity()));

	output("formatString(%d, 20)", typeCast.formatString("{}", 20));
	output("formatString(20abc20)", typeCast.formatString("{0}{1}{0}", 20, "abc"));

	return 0;
}