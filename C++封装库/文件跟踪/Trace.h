/********************************************************************
	created:	2017/12/14
	created:	14:12:2017   9:52
	filename: 	F:\code\GitProject\C-\ThinkingInC++\TraceFile\Trace.h
	file path:	F:\code\GitProject\C-\ThinkingInC++\TraceFile
	file base:	Trace
	file ext:	h
	author:		Masf
	
	purpose:	����һ�������ļ��������б������͵�cout������͵����
				�����ļ���
				Ҫʹ�ø��ļ�������ʹ��using��������������ȥ��coutǰ��
				�����ֿռ�ǰ׺��
*********************************************************************/
#ifndef TRACE_H
#define TRACE_H
#include <fstream>

#ifdef TRACEON
std::ofstream TRACEFILE__("TRACE.OUT");
#define cout	TRACEFILE__
#endif

#endif