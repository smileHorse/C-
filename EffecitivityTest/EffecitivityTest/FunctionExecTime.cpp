/*!
 * \file FunctionExecTime.h
 *
 * \author mateng
 * \date 四月 2019
 *
 * 函数执行时间
 */

#include "FunctionExecTime.h"

CFunctionExecTime::CFunctionExecTime(const string& funName)
	: m_funName(funName)
{
	m_start = clock();
}

CFunctionExecTime::~CFunctionExecTime()
{
	clock_t end = clock();
	cout << "FunctionExecTime - " << m_funName << " ellapsed: " << (end - m_start) << " ms." << endl;
}
