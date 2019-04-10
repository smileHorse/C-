/*!
 * \file FunctionExecTime.h
 *
 * \author mateng
 * \date 四月 2019
 *
 * 函数执行时间
 */

#ifndef FUNCTIONEXECTIME_H
#define FUNCTIONEXECTIME_H

#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class CFunctionExecTime
{
public:
	explicit CFunctionExecTime(const string& funName);
	~CFunctionExecTime();

private:
	string m_funName;
	clock_t m_start;
};
#endif
