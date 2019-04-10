/*!
 * \file DataStruct.h
 *
 * \author mateng
 * \date ËÄÔÂ 2019
 *
 * 
 */

#include <string>
#include <vector>
using namespace std;

class CDataStruct
{
public:
	CDataStruct() {}

public:
	int id;
	string name;
	string code;
	string desc;
	string address;
	string phone;
	vector<string> attributes;
	string array[30];
};