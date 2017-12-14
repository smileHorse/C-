/********************************************************************
	created:	2017/12/14
	created:	14:12:2017   9:52
	filename: 	F:\code\GitProject\C-\ThinkingInC++\TraceFile\Trace.h
	file path:	F:\code\GitProject\C-\ThinkingInC++\TraceFile
	file base:	Trace
	file ext:	h
	author:		Masf
	
	purpose:	创建一个跟踪文件，将所有本来被送到cout的输出送到这个
				跟踪文件。
				要使用该文件，必须使用using声明，这样可以去掉cout前面
				的名字空间前缀。
*********************************************************************/
#ifndef TRACE_H
#define TRACE_H
#include <fstream>

#ifdef TRACEON
std::ofstream TRACEFILE__("TRACE.OUT");
#define cout	TRACEFILE__
#endif

#endif