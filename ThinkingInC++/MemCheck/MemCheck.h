/********************************************************************
	created:	2017/12/14
	created:	14:12:2017   9:59
	filename: 	F:\code\GitProject\C-\ThinkingInC++\MemCheck\MemCheck.h
	file path:	F:\code\GitProject\C-\ThinkingInC++\MemCheck
	file base:	MemCheck
	file ext:	h
	author:		Masf
	
	purpose:	重载了运算符new，在某些平台上可能无法使用，而且只能用于
				不直接调用operator new()函数的程序。
				能够截获所有对new和delete的调用，并且通过在程序中调用宏
				MEM_ON()来初始化内存跟踪。所有有关内存分配和释放的踪迹
				都被打印到标准输出上。
				当想跟踪动态存储区的活动时，可以在任何源文件中包含这个
				文件，但它必须是所有被包含文件的最后一个。
				本文件中替换new的宏将会篡改库中源代码所使用的的所有new
				运算符的实例，可能会造成编译错误。
*********************************************************************/
#ifndef MEMCHECK_H
#define MEMCHECK_H
#include <cstddef>

// Usurp the new operator(both scalar and array versions)
void* operator new(std::size_t, const char*, long);
void* operator new[](std::size_t, const char*, long);
#define new new(__FILE__, __LINE__)

extern bool traceFlag;
#define TRACE_ON()	traceFlag = true
#define TRACE_OFF()	traceFlag = false

extern bool activeFlag;
#define MEM_ON()	activeFlag = true
#define MEM_OFF()	activeFlag = false

#endif