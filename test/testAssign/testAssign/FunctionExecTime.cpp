

#include "FunctionExecTime.h"
#include <iostream>
using namespace std;

CFunctionExecTime::CFunctionExecTime(const string& funName, bool show)
	: m_funName(funName), m_show(show)
{
	m_start = clock();
	m_end = clock();
}

CFunctionExecTime::~CFunctionExecTime()
{
	m_end = clock();
	long ellapsed = m_end - m_start;
	if (m_show || ellapsed >= 1)
	{
		cout << "CFunctionExecTime -- " << m_funName << " ellapsed " << ellapsed << " ms" << endl;
	}
}

void CFunctionExecTime::outputExecTime(const string& funName, const string& section, bool show /*= false*/)
{
	clock_t end = clock();
	long ellapsed = end - m_end;
	m_end = end;
	if (show || ellapsed >= 1)
	{
		cout << "CFunctionExecTime -- " << funName << " -- " << section << " -- ellapsed " << ellapsed << " ms" << endl;
	}
}
